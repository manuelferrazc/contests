#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
ll v[200'001];

ll fexp(ll n, ll e) {
    if(e==1) return n;

    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;
    return r;
}

ll count(ll n) {
    ll r=0;
    while(n) {
        r+=n&1;
        n>>=1;
    }
    return r;
}

ll calc(ll i, ll j, ll p, ll pos) {
    if(v[i]==v[j]) {
        ll n = j-i+1;
        n = n*n%mod;
        // cout << i << ' ' << j << ' ' << n*(count(v[i])+1)%mod << '\n';  
        return n*(count(v[i])+1)%mod;
    }

    if((v[i]&(1LL<<pos)) and (v[j]&(1LL<<pos))) return calc(i,j,p+1,pos-1);
    if(((v[i]&(1LL<<pos))==0) and ((v[j]&(1LL<<pos))==0)) return calc(i,j,p,pos-1);
    if((v[i]&(1LL<<pos)) and ((v[j]&(1LL<<pos))==0)) cout << "ERRO!!!!!!!\n";

    ll x = i;
    while((v[x]&(1LL<<pos))==0) x++;
    ll n1 = x-i, n2 = j-x+1;
    ll r=n1*n2%mod*p%mod;

    r+=n1*n2%mod*(p+1);
    r%=mod;
    r = (r + calc(i,x-1,p,pos-1)+calc(x,j,p+1,pos-1))%mod;
    // cout << i << ' ' << j << ' ' << r << '\n';  

    return r;
}

void solve() {
    ll n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v,v+n);
    // for(int i=0;i<n;i++) cout << v[i] << ' ';
    // cout << '\n';

    cout << calc(0,n-1,1,33 )*fexp(n*n%mod,mod-2)%mod << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
