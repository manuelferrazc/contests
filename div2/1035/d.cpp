#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,m;

ll fexp(ll nn, ll e) {
    if(e==0) return 1;
    if(e==1) return nn;
    
    ll r=fexp(nn,e>>1);
    r=r*r%m;
    if(e&1) r = r*nn%m;

    return r;
}

void solve() {
    cin >> n >> m;


    ll ans=0;
    

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
