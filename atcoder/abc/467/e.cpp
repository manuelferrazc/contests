#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll calc(vector<ll> v, ll *b, ll m) {
	ll r=0;

	for(ll i=v.size()-2;i>=0;i--) {
		ll s = v[i]+v[i+1];
		ll dif = b[i] - s + 2*m;
		dif %= m;

		v[i]+=dif;
		r+=dif;
	}

	return r;
}


int main() { _
	ll n,m;
	cin >> n >> m;

	vector<ll> a(n);
	ll b[n-1];

	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) cin >> b[i];

	ll ans = calc(a,b,m);

	ll s = a[n-2]+a[n-1];
	ll dif = b[n-2] - s + 2*m;
	dif %= m;

	a[n-1]+=dif;

	ans = min(ans,dif+calc(a,b,m));

	cout << ans << '\n';

    return 0;
}
