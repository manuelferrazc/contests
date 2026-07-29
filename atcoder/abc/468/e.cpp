#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

void build(ll *v, ll *sp, ll n) {
	sp[0] = v[0];
	for(int i=1;i<n;i++) sp[i] = (sp[i-1]+v[i])%mod;
}

ll get(ll *sp, int l, int r) {
	if(l==0) return sp[r];
	return (sp[r]-sp[l-1]+mod)%mod;
}

ll fexp(ll n, ll e) {
	ll r=1;
	while(e) {
		if(e&1) r = r*n%mod;
		e/=2;
		n = n*n%mod;
	}
	return r;
}

int main() { _
	int n;
	cin >> n;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	ll sp[n];
	build(v,sp,n);

	ll ans = 0;
	ll sum = get(sp,0,n-1);
	ans = sum;

	for(int i=1;i<n;i++) {
		sum -= get(sp,n-i,n-1);
		sum = (sum+mod)%mod;
		
		sum += get(sp,i,n-1);
		sum %= mod;

		ans += sum*fexp(i+1,mod-2);
		ans %= mod;
	}

	cout << ans << '\n';

    return 0;
}
