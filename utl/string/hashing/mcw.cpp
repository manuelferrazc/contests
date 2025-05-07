#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;
const ll p = 200'003;

vector<ll> pot;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;

    return r;
}

ll invp,invm;

ll hashh(vector<ll> &v, ll n) {
    ll r=0;
    for(ll i=0;i<n;i++) r = (r+v[i]*pot[i])%mod;
    return r;
}

ll sg(ll a1) {
    return ((a1*(pot.back()*p%mod-1+mod)%mod)*invp%mod);
}

int main() { _
    ll n,w,ans=0;
    cin >> n >> w;
    if(w>n) {
        cout << "0\n";
        return 0;
    }

    invp = fexp(p-1,mod-2);
    invm = fexp(p,mod-2);

    pot.push_back(1);
    for(ll i=1;i<w;i++) pot.push_back(pot.back()*p%mod);

    vector<ll> a(n),b(w);
    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;

    const ll hp = hashh(b,w);
    ll ht = hashh(a,w);

    ll sla = sg(a[0]-b[0]);

    if(hp==((ht-sla+mod)%mod)) ans++;

    for(ll i=0;i+w<n;i++) {
        ht = (ht-a[i]+mod)%mod;
        ht = ht*invm%mod;
        ht = (ht+a[i+w]*pot.back())%mod;

        if(hp==(ht-sg(a[i+1]-b[0])+mod)%mod) ans++;
    }

    cout << ans << '\n';

    return 0;
}
