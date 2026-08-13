#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int mod = 998244353;
#define MAX 300'000

ll fat[MAX];
ll ifat[MAX];

ll fexp(ll n, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = r*n%mod;
		e/=2;
		n = n*n%mod;
	}
	return r;
}

ll comb(ll n, ll k) { // n escolhe k
	return (fat[n]*ifat[k]%mod)*ifat[n-k]%mod;
}

void solve() {
	ll n,m,k;
	cin >> n >> m >> k;

	ll ans = 0;

	for(int i=0;i<=m;i++) {
		ll um = 1 - (i&1)*2;
		ll sup = k - i*n;
		if(sup<0) continue;
		ans += (comb(m,i)*comb(sup+m-1,m-1)%mod)*um + mod;
		ans %= mod;
	}

	cout << ans << '\n';
}

int main() { _
	fat[0] = 1;
	for(int i=1;i<MAX;i++) fat[i] = fat[i-1]*i%mod;
	ifat[MAX-1] = fexp(fat[MAX-1],mod-2);
	for(int i=MAX-1;i>=1;i--) ifat[i-1] = ifat[i]*i%mod;

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
