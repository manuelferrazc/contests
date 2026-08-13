#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 1'000'000

// qtd, sum
pair<ll,ll> st[4*MAX];

void add(int pos, int l, int r, int i, int x) {
	st[pos].ff++;
	st[pos].ss+=x;
	if(l==r) return;

	int m = (l+r)/2;
	if(i<=m) add(2*pos+1,l,m,i,x);
	else add(2*pos+2,m+1,r,i,x);
}

ll find(int pos, int l, int r, ll tg) {
	//cout << l << ' ' << r << '\n';
	if(st[pos].ss<tg) {
	//	cout << -1 << '\n';
		return -1;
	}
	if(l==r) {
	//	cout << 1 << '\n';
		return 1;
	}
	int m = (l+r)/2;
	int ls = 2*pos+1;
	if(st[ls+1].ss>=tg) return find(ls+1,m+1,r,tg);
	else return st[ls+1].ff+find(ls,l,m,tg-st[ls+1].ss);
}

void solve() {
	int n,m;
	cin >> n >> m;
	fill(st,st+4*n*m,pair(0ll,0ll));

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	ll t[n][m];
	vector<array<ll,3>> s;
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		cin >> t[i][j];
		s.push_back({t[i][j],i,j});
	}

	sort(s.begin(),s.end());

	ll ans = m;

	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<m;j++) {
			auto it = lower_bound(s.begin(),s.end(),array<ll,3>({t[i][j],i,j}));
			add(0,0,n*m-1,it-s.begin(),t[i][j]);
		}

		ll qtd = find(0,0,n*m-1,v[i]);
		//cout << i << ' ' << qtd << '\n';
		if(qtd!=-1) ans = min(ans,qtd);
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
