#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

map<ll,ll> m;
ll n,c;

ll calc(ll x) {
    ll act=0,qtd=0;
    for(ll i=0;i<m[x] and act+x<=c;i++) {
        act+=x;
        qtd++;
    }

    ll r=act;
    if(m.count(x+1)) {
        for(ll i=0;i<m[x+1];i++) {
            while(act+x+1>c and qtd) {
                qtd--;
                act-=x;
            }
            if(act+x+1>c) break;
            act+=x+1;
            r=max(r,act);
        } 
    }
    return r;
}

void solve() {
    m.clear();
    cin >> n >> c;
    for(ll i=0;i<n;i++) {
        ll x;
        cin >> x;
        m[x]++;
    }

    ll ans=0;
    for(auto [a,b]:m) ans=max(ans,calc(a));
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
