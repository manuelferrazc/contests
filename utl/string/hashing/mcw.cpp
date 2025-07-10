#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;
ll b = 200'003;

ll pot = 1;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}
 
template<int MOD> struct str_hash { // 116fcb
	static ll P;
	vector<ll> h, p;
	str_hash(vector<ll> &s) : h(s.size()), p(s.size()) {
        b = P;
		p[0] = 1, h[0] = s[0];
		for (int i = 1; i < s.size(); i++)
			p[i] = p[i - 1]*P%MOD, h[i] = (h[i - 1]*P + s[i])%MOD;
	}
	ll operator()(int l, int r) { // retorna hash s[l...r]
		ll hash = h[r] - (l ? h[l - 1]*p[r - l + 1]%MOD : 0);
		return hash < 0 ? hash + MOD : hash;
	}
};
template<int MOD> ll str_hash<MOD>::P = uniform(256, MOD - 1);

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;

    return r;
}

ll invp;

ll sg(ll a1) {
    return ((a1*(pot-1+mod)%mod)*invp%mod);
}

int main() { _
    ll n,w,ans=0;
    cin >> n >> w;
    
    vector<ll> A(n),B(w);
    for(ll &i:A) cin >> i;
    for(ll &i:B) cin >> i;
    
    str_hash<mod> ha(A), hb(B);
    
    pot = fexp(b,w);
    invp = fexp(b-1,mod-2);

    const ll hp = hb(0,w-1);

    for(ll i=n-1;i-w>=-1;i--) {
        if(hp== (ha(i-w+1,i)-sg(A[i]-B.back())+mod)%mod) ans++;
    }

    cout << ans << '\n';

    return 0;
}
