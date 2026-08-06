#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

const ll mod = 998244353;

ll fat[200'001];

ll fexp(ll n, ll e) {
	ll r=1;
	while(e) {
		if(e&1) r = r*n%mod;
		e>>=1;
		n = n*n%mod;
	}
	return r;
}

ll comb(ll n, ll k) {
	ll num = fat[n];
	ll den = fat[k]*fat[n-k]%mod;
	return num*fexp(den,mod-2)%mod;
}

int main() { _
	fat[0] = 1;
	for(int i=1;i<=200000;i++) fat[i] = fat[i-1]*i%mod;

	ll n,k;
	cin >> n >> k;
	
	ll dp[k+1];
	dp[0] = 0;
		
	for(int i=1;i<=k;i++) {
		ll f = fexp(i,n);
		dp[i] = f*comb(k,i)%mod;
		//cout << "i = " << i << ", f = " << f << ", comb = " << comb(k,i) << '\n';
		//s += dp[i];
		//s%=mod;
	}

	//for(int i=1;i<=k;i++) cout << i << ": " << dp[i] << '\n';

	ll ans = 0;
	for(int i=k;i>=1;i-=2) ans = (ans+dp[i])%mod;
	for(int i=k-1;i>=1;i-=2) ans = (ans+mod-dp[i])%mod;

	cout << ans*fexp(fexp(k,n),mod-2)%mod << '\n';

	return 0;
}
