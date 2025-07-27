#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

auto solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i=0;i<n;i++) cin >> v[i];
    ll m = v[0];
    for(ll i=1;i<n;i++) {
        if(v[i]>=2*m) return "NO\n";
        m = min(m,v[i]);
    }

    return "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
