#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define int ll

#define MAX 200100

ll st[4*MAX];
ll lazy[4*MAX];

void build(int p, int l, int r) {
	lazy[p] = 1;
	st[p] = r-l+1;
	if(l!=r) {
		int m = (l+r)/2;
		build(2*p,l,m);
		build(2*p+1,m+1,r);
	}
}

void prop(int p, int l, int r) {
	st[p]*=lazy[p];
	if(l!=r) {
		lazy[2*p]*=lazy[p];
		lazy[2*p+1]*=lazy[p];
	}
	lazy[p] = 1;
}

ll add(int p, int l, int r, int i, ll x) {
	prop(p,l,r);
	if(i<l or r<i) return st[p];
	if(l==r) return (st[p]+=x);
	int m = (l+r)/2;
	return st[p] = add(2*p,l,m,i,x)+add(2*p+1,m+1,r,i,x);
}

ll mult(int p, int l, int r, int lq, int rq) {
	prop(p,l,r);
	if(rq<l or r<lq) return st[p];
	if(lq<=l and r<=rq) {
		lazy[p]*=2;
		prop(p,l,r);
		return st[p];
	}

	int m = (l+r)/2;
	return st[p] = mult(2*p,l,m,lq,rq)+mult(2*p+1,m+1,r,lq,rq);
}

ll query(int p, int l, int r, int lq, int rq) {
	prop(p,l,r);
	if(rq<l or r<lq) return 0;
	if(lq<=l and r<=rq) return st[p];
	int m = (l+r)/2;
	ll x = query(2*p,l,m,lq,rq)+query(2*p+1,m+1,r,lq,rq);
	assert(x>=1);
	return x;
}

int find(int p, int l, int r, ll q) {
	prop(p,l,r);
	if(l==r) return l;
	int m = (l+r)/2;
	prop(2*p,l,m);
	prop(2*p+1,m+1,r);
	//cout << l << ' ' << r << " -> " << st[p] << ", com q = " << q << '\n';
	if(st[2*p]<q) return find(2*p+1,m+1,r,q-st[2*p]);
	return find(2*p,l,m,q);
}

signed main() { _
	int n,q;
	cin >> n >> q;

	build(1,0,n-1);
	string s;
	cin >> s;
	//cout << s << '\n';
	//cout << s.size() << '\n';
	
		//for(int i=0;i<n;i++) cout << query(1,0,n,i,i) << ' ';
		//cout << '\n';
	while(q--) {
		ll op;
		cin >> op;
		
		if(op==1) {
			ll l,r;
			cin >> l >> r;

			int idl = find(1,0,n-1,l);
			int idr = find(1,0,n-1,r);
			if(idl==idr) {
				add(1,0,n-1,idl,r-l+1);
				continue;
			}

			// add -> soma em ponto
			// query -> consulta em range 
			// mult -> multiplica range por 2

			// idl = pode conter prefixo anterior a l
			// idr pode conter sufixo dps de r

			// lq1 -> soma do range [0,idl]
			ll lq1 = query(1,0,n-1,0,idl);

			//ll rq = query(1,0,n,idl,idr);
			ll rq1 = 0;
			if(idr) rq1 = query(1,0,n-1,0,idr-1);
			add(1,0,n-1,idl,lq1-l+1);
			add(1,0,n-1,idr, r-rq1);
	
			if(idl+1<=idr-1) mult(1,0,n-1,idl+1,idr-1);
			//cout << "idl,idr = " << idl  << ',' << idr << ", lq1,rq1 = " << lq1 << ',' << rq1 << '\n';
		} else {
			ll l;
			cin >> l;
			int id = find(1,0,n-1,l);
			cout << s[id] << '\n';
		}

		//for(int i=0;i<n;i++) cout << query(1,0,n-1,i,i) << ' ';
		//cout << '\n';
	}

	exit(0);
}
