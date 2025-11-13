#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll solve() {
    ll n;
    cin >> n;

    ll mx = INT_MIN;
    ll mx2 = 0;
    ll x;

    for(ll i=0;i<n;i++) {
        cin >> x;
        mx2 = max(mx2,mx-x);
        mx = max(mx,x);
    }

    for(int i=0;;i++) if(((1ll<<i)-1)>=mx2) return i;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
