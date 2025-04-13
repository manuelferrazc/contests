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
    for(auto &[i,j]:v) cin >> i;
    for(auto &[i,j]:v) cin >> j;

    sort(v.begin(),v.end());
    for(ll i=0;i<n;i++) {
        if(v[i].ff>k) break;
        k+=v[i].ss;
    }
    cout << k << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
