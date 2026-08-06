#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	ll n;
	cin >> n;

	ll v[n];
	ll s=0;
	for(int i=0;i<n;i++) {
		cin >> v[i];
		s+=v[i];
	}

	ll dp[1<<n];
	for(int m = (1<<n)-1;m>=0;m--) {
		ll sum=0;
		for(int i=0;i<n;i++) if(m&(1<<i)) sum+=v[i];
		
		ll qtd = max(sum,s-sum)-min(sum,s-sum);
		ll x = LLONG_MIN;

		for(int i=0;i<n;i++) if((m&(1<<i))==0) x = max(x,dp[m+(1<<i)]);
		if(x!=LLONG_MIN) dp[m] = min(x,qtd);
		else dp[m] = qtd;
		//cout << m << ' ' << dp[m] << '\n';
	}

	// N - V = dp[0]
	// N + V = s
	//ll l=0,r=1'000'000'000'000ll;
	
	ll novo = (dp[0]+s)/2;
	ll velho = s-novo;
	cout << novo << ' ' << velho << '\n';

	return 0;
}
