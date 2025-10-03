#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,xk,yk,xd,yd;
    cin >> n >> xk >> yk >> xd >> yd;

    ll ans = 0;

    if(xk==xd) {
        if(yk<yd) ans = yd;
        else ans = n-yd;
    } else if(yk==yd) {
        if(xk<xd) ans = xd;
        else ans = n-xd;
    } else if(xk<xd and yk<yd) ans = max(xd,yd);
    else if(xk<xd) ans = max(xd,n-yd);
    else if(yk<yd) ans = max(n-xd,yd);
    else ans = max(n-xd,n-yd);

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
