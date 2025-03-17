#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m;
    cin >> n >> m;

    vector<ll> v(m);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());
    ll ans=0;
        // cout << i << ' ' << ans << '\n';

    for(int i=1;i<n;i++) {
        ll qi = m-(lower_bound(v.begin(),v.end(),i)-v.begin());
        ll qni = m-(lower_bound(v.begin(),v.end(),n-i)-v.begin());
        if(i==n-i) ans+=qi*(qi-1);
        else if(i<n-i) ans+=qi*qni-qni;
        else ans+=qi*qni-qi;
        // cout << i << ' ' << ans << ' ' << qi << ' ' << qni << '\n';
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
