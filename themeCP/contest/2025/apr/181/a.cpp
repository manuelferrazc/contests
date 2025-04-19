#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll count(ll a) {
    set<ll> m;
    string s = to_string(a);
    for(char c:s) m.insert(c-'0');
    return *m.rbegin()-*m.begin();
}

void solve() {
    ll l, r;
    cin >> l >> r;

    ll ans=l,m=0;
    for(ll i=0;i<100 and i+l<=r;i++) {
        ll x=count(i+l);
        if(x>m) {
            m=x;
            ans=i+l;
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
