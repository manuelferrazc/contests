#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1?r*n%mod:r;
}

void solve() {
    ll a,b;
    cin >> a >> b;
    cout << fexp(a,b) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
