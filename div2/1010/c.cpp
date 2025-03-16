#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

ll fexp(ll n, ll e) {
    if(e==1) return n;
    if(e==0) return 1;

    ll r=fexp(n,e>>1);
    r=r*r%mod;
    if(e&1) r = r*n%mod;
    return r;
}

const ll inv = fexp(2,mod-2);

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    
    ll ans=0;
    for(ll i=n-1;i;i--) {
        if(s[i]=='1') ans = (ans + 1)*inv%mod;
        else ans = ans*inv%mod;
    }

    cout << (n-1+ans)%mod << '\n';
    // these questions don't even make sense
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
