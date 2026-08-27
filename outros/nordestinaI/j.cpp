#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 200'100

int st[4*MAX];
int v[MAX];

int build(int p, int l, int r) {
	if(l==r) return st[p] = v[l];
	int m = (l+r)/2;
	return st[p] = max(build(2*p,l,m),build(2*p+1,m+1,r));
}

int query(int p, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return INT_MIN;
	if(lq<=l and r<=rq) return st[p];

	int m = (l+r)/2;
	return max(query(2*p,l,m,lq,rq),query(2*p+1,m+1,r,lq,rq));
}

int main() { _
	int n,q;
	cin >> n >> q;

	int pos[n+1];
	for(int i=0;i<n;i++) {
		cin >> v[i];
		pos[v[i]] = i;
	}

	build(1,0,n-1);

	string p1 = "Adilson\n";
	string p2 = "Reginaldo\n";

	while(q--) {
		int l,r;
		cin >> l >> r;
		l--;
		r--;
		
		int mx = query(1,0,n-1,l,r);
		int p = pos[mx];
		if(p==l or p==r) cout << p1;
		else {
			int ql = p-l-1;
			int qr = r-p-1;

			int s = ql+qr;
			if(s%2) cout << p1;
			else cout << p2;
		}
	}

	exit(0);
}
