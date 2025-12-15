#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll p[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

void solve() {
    ll ans = 53;

    int n;
    cin >> n;

    while(n--) {
        ll x;
        cin >> x;
        for(ll i:p) {
            if(x%i) {
                ans = min(ans,i);
                break;
            }
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
