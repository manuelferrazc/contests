#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007LL;
const ll p = 41LL;
ll n,m;
vector<ll> pt;

ll fexp(ll nn, ll e) {
    if(e==0) return 1;
    if(e==1) return nn;

    ll r = fexp(nn,e>>1);
    r = (r*r)%mod;
    if(e&1) r = (r*nn)%mod;
    return r;
}

ll hashm(string &s) {
    ll r = 0;
    for(ll i=0;i<m;i++) r = (r+(s[i]-'a'+1LL)*pt[i])%mod;
    return r;
}

int main() { _
    string a,b;
    cin >> a >> b;
    n=a.size(),m=b.size();
    if(m>n) {
        cout << 0 << '\n';
        return 0;
    }
    const ll inv = fexp(p,mod-2);

    pt.push_back(1);
    for(ll i=1;i<m;i++) pt.push_back((pt.back()*p)%mod);

    const ll hb = hashm(b);
    ll ha = hashm(a);

    ll ans = (hb==ha?1:0);
    for(ll i=0;i+m<n;i++) {
        ha = (ha-(a[i]+1LL-'a')+mod)%mod;
        ha = (inv*ha)%mod;
        ha = (ha+pt.back()*(a[i+m]+1LL-'a'))%mod;
        if(ha==hb) ans++;
    }

    cout << ans << '\n';

    return 0;
}
