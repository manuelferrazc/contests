#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
#define int ll

void solve() {
	ll n,f;
	cin >> n >> f;

	vector<int> p(n),pans;
	iota(p.begin(),p.end(),1);

	int l[n+1],r[n+1];
	l[0] = 0;
	r[0] = f;
	for(int i=1;i<=n;i++) cin >> l[i] >> r[i];

	ll ans = LLONG_MAX;

	do {
		ll act = f;
		ll val = 0;
		for(int i=1;i<=n;i++) {
			int id = p[i-1];
			int idant = 0;
			if(i>1) idant = p[i-2];

			val += max (l[id] - r[idant],0ll) + r[id] - l[id];
		}

		if(ans>val) {
			ans = val;
			pans = p;
		}

	} while(next_permutation(p.begin(),p.end()));

	cout << ans << '\n';
}

signed main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
