#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,x;
    cin >> n >> x;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.rbegin(),v.rend());

    ll ans=0,s=0;
    for(ll i=0;i<n;i++) {
        s++;
        if(s*v[i]>=x) {
            ans++;
            s=0;
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
