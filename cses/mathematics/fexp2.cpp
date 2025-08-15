#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

ll fexp(ll x, ll y) { // iterativo
	ll ret = 1;
	while (y) {
		if (y & 1) ret = (ret * x) % mod;
		y >>= 1;
		x = (x * x) % mod;
	}
	return ret;
}

ll fexp(ll a, ll b, ll c) {
    if(c==0) return a;
    if(c==1) return fexp(a,b);

    ll e2 = fexp(b,(c>>1)+(c&1));
    ll x = fexp(a,b,c>>1);
    return fexp(x,e2);
}

void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    cout << fexp(a,b,c) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
