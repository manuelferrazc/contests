#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

ll fat[200'001];
ll ifat[200'001];

void solve() {
	int n;
	cin >> n;

	ll ans = 1;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	if(n!=14) return;
	for(int m=1;m<(1<<n);m++) {
		vector<int> v;
		for(int i=0;i<n;i++) if(m&(1<<i)) v.push_back(a[i]);
		ll s = 0;
		for(int i=0;i<(int)v.size();i++) s += (i&1 ? -1 : 1)*v[i];

		if(s==0) {
			for(int i:v) cout << i << ' ';
			cout << '\n';
			ans++;
		}
	}

	cout << ans << '\n';
}

int main() { _

	//for(int i=0;i<=200000;i++) if(ifat[i]*fat[i]%mod != 1) exit(0);

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
