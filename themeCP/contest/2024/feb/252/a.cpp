#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,m,q;
    cin >> n >> m >> q;
    vector<ll> v(m);
    for(auto &i:v) cin >> i;
    sort(v.begin(),v.end());

    while(q--) {
        ll a;
        cin >> a;

        auto x = lower_bound(v.begin(),v.end(),a);
        if(x==v.end()) cout << n-v.back() << '\n';
        else if(*x==a) cout << 0 << '\n';
        else if(x==v.begin()) cout << *x-1 << '\n';
        else cout << (*x-*prev(x))/2 << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
