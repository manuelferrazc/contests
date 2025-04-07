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
    ll ans=2, act=n+1;
    while(act%(n<<2)) ans++,act+=n+1;
    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
