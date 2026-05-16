#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
ll *fat;

ll fexp(ll n, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = r*n%mod;
		n = n*n%mod;
		e>>=1;
	}
	return r;
}

ll comb(ll n,ll k) {
	ll num = fat[n+k-1];
	ll den = fat[n]*fat[k-1]%mod;
	return num*fexp(den,mod-2)%mod;
}

int main() { _
	fat = new ll[10'000'000];
	fat[0] = 1;
	for(int i=1;i<10000000;i++) fat[i] = fat[i-1]*i%mod;

	int x1,x2,x3;
	cin >> x1 >> x2 >> x3;

	ll ans = 0;

	for(int b = 2;b<=x2+1;b++) {
		int q1 = (b+1)/2;
		int q3 = b-q1;
		if(q1>x1 or q3>x3) break;

		ll tot = comb(x1-q1,q1)*comb(x3-q3,q3)%mod;
		
		ll q2free = x2-b+1;

		ans += tot*comb(q2free,x1+x3+1);
		ans %= mod;

		//cout << ans << ' ' << tot << '\n';
	}

	//cout << ans << ' ';

	for(int b=2;b<=x2+1;b++) {
		int q3 = (b+1)/2;
		int q1 = b-q3;
		if(q1>x1 or q3>x3) break;

		ll tot = comb(x1-q1,q1)*comb(x3-q3,q3)%mod;
		ll q2free = x2-b+1;

		ans += tot*comb(q2free,x1+x3+1);
		ans %= mod;
	}

	cout << ans << '\n';

	delete[] fat;
	return 0;
}
