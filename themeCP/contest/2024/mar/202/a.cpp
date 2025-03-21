#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,p;
    cin >> n >> p;

    map<ll,ll> m;
    m.insert(make_pair(p,INT_MAX));

    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++) cin >> v[i].ss;
    for(ll i=0;i<n;i++) cin >> v[i].ff;
    sort(v.begin(),v.end());
    ll ans=0;
    for(ll i=0;i<n;i++) {
        auto it = m.begin();
        ans+=it->ff;
        it->ss--;
        if(m.count(v[i].ff)) m.at(v[i].ff)+=v[i].ss;
        else m.insert(v[i]);
        if(it->ss==0) m.erase(it);
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
