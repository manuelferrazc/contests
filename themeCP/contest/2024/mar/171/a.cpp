#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b;
    cin >> a >> b;
    for(ll i=0;;i++) {
        if(((a>>i)&1LL)!=((b>>i)&1LL)) {
            cout << (1LL<<i) << '\n';
            return;
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
