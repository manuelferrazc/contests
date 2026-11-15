#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 300300

pair<int,int> st[4*MAX]; // min,max
int v[MAX];
typedef pair<int,int> pii;

pair<int,int> comb(pii a, pii b) {
	pair<int,int> r;
	r.ff = min(a.ff,b.ff);
	r.ss = max(a.ss,b.ss);
	return r;
}

void build(int p, int l, int r) {
	if(l==r) {
		if(v[l]==-1) st[p] = pair(INT_MAX,INT_MIN);
		else st[p] = pair(v[l],v[r]);
		return;
	}

	int m = (l+r)/2;
	build(2*p,l,m);
	build(2*p+1,m+1,r);
	st[p] = comb(st[2*p],st[2*p+1]);
}

pii get(int p, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return pair(INT_MAX,INT_MIN);
	if(lq<=l and r<=rq) return st[p];

	int m = (l+r)/2;
	return comb( get(2*p,l,m,lq,rq), get(2*p+1,m+1,r,lq,rq) );
}

pii update(int p, int l, int r, int i, int x) {
	if(i<l or r<i) return st[p];
	if(l==r) {
		if(x==-1) return st[p] = pair(INT_MAX,INT_MIN);
		else return st[p] = pair(x,x);
	}

	int m = (l+r)/2;
	return st[p] = comb( update(2*p,l,m,i,x), update(2*p+1,m+1,r,i,x) );
}

int main() { _
	int n,q;
	cin >> n >> q;

	for(int i=0;i<n;i++) cin >> v[i];

	build(1,0,n-1);
	while(q--) {
		int op;
		cin >> op;

		if(op==1) { // update
			int i,x;
			cin >> i >> x;
			i--;

			update(1,0,n-1,i,x);
			v[i] = x;
		} else {
			int l,r;
			cin >> l >> r;
			l--;
			r--;

			auto [mi,ma] = get(1,0,n-1,l,r);

			//cout << mi << ' ' << ma << "\n";
			if(mi==INT_MAX or mi==ma) cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}
