#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    ll mx;
    cin >> mx;
    ll g=mx;
    for(ll i=1;i<n;i++) {
        cin >> mx;
        g=gcd(g,mx);
    }

    cout << ((mx/g)-1)+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
