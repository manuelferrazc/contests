#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'000

int st[4*MAX];
int v[MAX];

int build(int pos, int l, int r) {
	if(l==r) return st[pos] = v[l];
	int m = (l+r)/2;
	int ls = 2*pos+1;

	return st[pos] = build(ls,l,m)+build(ls+1,m+1,r);
}

int get(int pos, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return 0;
	if(lq<=l and r<=rq) return st[pos];

	int m = (l+r)/2;
	int ls = 2*pos+1;
	return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
}

void solve() {
	int n,q;
	string s;
	cin >> n >> q >> s;

	for(int i=0;i<n;i++) v[i] = 0;
	for(int i=0;i<n-1;i++) if(s[i]==s[i+1]) v[i]++;
	build(0,0,n-1);

	while(q--) {
		int l,r,k;
		cin >> l >> r >> k;
		l--;
		r--;

		if(l==r) cout << "YES\n";
		else {
			int cu = get(0,0,n-1,l,r-1);
			if(k>=(cu+1)/2) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
