#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct SegTree {
	int n;
	int *st;
	int *qtd;
	int *lazy;

	void build(int pos, int l, int r) {
		if(l==r) {
			st[pos] = 0;
			qtd[pos] = 1;
			lazy[pos] = 0;
		} else {
			int ls = 2*pos+1, m = (l+r)>>1;
			build(ls,l,m);
			build(ls+1,m+1,r);
			qtd[pos] = r-l+1;
			st[pos] = lazy[pos] = 0;
		}
	}

	SegTree(int _n) {
		n = _n;
		st   = new int[4*n];
		qtd  = new int[4*n];
		lazy = new int[4*n];

		build(0,0,n-1);
	}

	~SegTree() {
		delete[] st;
		delete[] qtd;
		delete[] lazy;
	}
	
	void propag(int pos, int l, int r) {
		st[pos]+=lazy[pos];
		if(l!=r) {
			int ls = 2*pos+1;
			lazy[ls]+=lazy[pos];
			lazy[ls+1]+=lazy[pos];
		}
		lazy[pos] = 0;
	}

	pair<int,int> add(int pos, int l, int r, int lq, int rq, int val) {
		propag(pos,l,r);
		if(rq<l or r<lq) return pair(st[pos],qtd[pos]);
		if(lq<=l and r<=rq) {
			lazy[pos]+=val;
			propag(pos,l,r);
			return pair(st[pos],qtd[pos]);
		}

		int ls = 2*pos+1, m = (l+r)>>1;
		auto [m1,q1] = add(ls,l,m,lq,rq,val);
		auto [m2,q2] = add(ls+1,m+1,r,lq,rq,val);

		if(m1==m2) {
			st[pos] = m1;
			qtd[pos] = q1+q2;
		} else if(m1<m2) {
			st[pos] = m1;
			qtd[pos] = q1;
		} else {
			st[pos] = m2;
			qtd[pos] = q2;
		}

		return pair(st[pos],qtd[pos]);
	}

	void add(int l, int r, int val) {
		add(0,0,n-1,l,r,val);
	}

	pair<int,int> get(int pos, int l, int r, int lq, int rq) {
		if(rq<l or r<lq) {
			// cout << l << ' ' << r << " MX" << '\n';
			return pair(INT_MAX,-1);
		}
		propag(pos,l,r);
		if(lq<=l and r<=rq) {
			// cout << l << ' ' << r << ' ' << st[pos] << ' ' << qtd[pos] << '\n';
			return pair(st[pos],qtd[pos]);
		}
		
		int ls = 2*pos+1, m = (l+r)/2;
		auto [m1,q1] = get(ls,l,m,lq,rq);
		auto [m2,q2] = get(ls+1,m+1,r,lq,rq);

		int r1,r2;
		if(m1==m2) r1=m1,r2=q1+q2;
		else if(m1<m2) r1=m1,r1=q1;
		else r1=m2,r2=q2;
		// return pair(m1,q1);
		// else return pair(m2,q2);

		return pair(r1,r2);
		// println("{} {} {} {}",l,r,r1,r2);
	}

	ll area(int l, int r) {
		auto [mi,qt] = get(0,0,n-1,l,r);
		// println("mi = {}",mi);
		if(mi==0) {
			// println("retornando mi {}",n-qt);
			return n-qt;
		}
		// cout << "retornando " << mi << ' ' << n << '\n';
		return n;
	}
};

int main() { _
	ll ans=0;
	int n;
	cin >> n;

	SegTree st(2'000'001);

	vector<array<int,3>> ev;
	array<int,4> v[n];

	for(int i=0;i<n;i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2] >> v[i][3];

		v[i][0]+=1'000'000;
		v[i][1]+=1'000'000;
		v[i][2]+=1'000'000;
		v[i][3]+=1'000'000;
		
		ev.push_back({v[i][0],2,i});
		ev.push_back({v[i][2],1,i});
	}

	sort(ev.begin(),ev.end());
	// cout << st.area(0,2'000'000) << '\n';

	// st.add(1,2,1);
	// cout << st.area(0,2'000'000) << '\n';


	// exit(0);

	for(int i=0;i<2*n;i++) {
		// cout << ev[i][0] << '\n';
		int id = ev[i][2];
		
		int y1 = v[id][1], y2 = v[id][3];
		ll pans = ans;
		// cout << ans << ' ';
		
		if(ev[i][1]==1) {
			// cout << "CASO 1 ";
			st.add(y1,y2-1,-1);
			
			// somei tudo menos o prox evento ("intervalo aberto" no final)
			if(ev[i+1][0]!=ev[i][0]) ans+=st.area(0,2'000'000)*(ev[i+1][0]-ev[i][0]);
		} else {
			// cout << "CASO 2 ";
			// if(ev[i-1][1]==1 or ev[i-1][0]!=ev[i][0]) ans+=st.area(0,2'000'000);
			st.add(y1,y2-1,1);

			if(i<2*n-1 and ev[i+1][0]!=ev[i][0]) ans+=st.area(0,2'000'000)*(ev[i+1][0]-ev[i][0]);
		}
		// cout << pans << ' ' << ans << '\n';
	}

	cout << ans << '\n';

	return 0;
}
