#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll fexp(ll n, ll e, ll mod=1'000'000'007) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1,mod);
    return e&1 ? r*n%mod : r;
}

void solve() {
    ll a,b,c;
    cin >> a >> b >> c;
    cout << fexp(a,fexp(b,c,1'000'000'006)) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
