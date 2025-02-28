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

    vector<ll> v(n);
    for(auto &i:v) cin >> i;

    for(ll i=0;;i++) {
        for(ll j=1;j<n;j++) {
            if(((v[j]>>i)&1LL)^((v[j-1]>>i)&1LL)) {
                cout << (1LL<<(i+1)) << '\n';
                return;
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
