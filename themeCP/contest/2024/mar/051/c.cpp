#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m,ans=0;
    cin >> n >> m;
    pair<ll,ll> range = make_pair(max(n-m,0LL),n+m);

    for(ll i=0;i<33;i++) {
        if(range.ff&(1LL<<i)) ans|=(1LL<<i);
        else {
            ll mod = (1LL<<i) - (range.ff%(1LL<<i));
            if(mod+range.ff<=range.ss) ans|=(1LL<<i);
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
