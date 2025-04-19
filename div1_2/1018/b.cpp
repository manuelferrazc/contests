#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> v(n);
    for(auto &i:v) cin >> i.ff;
    for(auto &i:v) cin >> i.ss;

    vector<ll> v2(n);
    ll ans=1;
    for(ll i=0;i<n;i++) {
        ans+=max(v[i].ff,v[i].ss);
        v2[i] = min(v[i].ff,v[i].ss);
    }
    sort(v2.rbegin(),v2.rend());
    for(ll i=0;i<k-1;i++) ans+=v2[i];
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
