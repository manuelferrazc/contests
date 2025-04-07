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
    if(n&1LL) {
        if((n>>1)&1) cout << n+1 << '\n';
        else cout << 2*n+1 << '\n';
    } else cout << (n<<2)+1 << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
