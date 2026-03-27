#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll k,l1,r1,l2,r2;
    cin >> k >> l2 >> r2 >> l1 >> r1;

    ll ans = 0;

    ll kp = 1;

    while(true) {
        // encontrar

        ll l = l2,r = r2;
        ll miny = -1;

        // kp = x/y;
        // x = kp*y;

        while(l<=r) {
            ll y = (l+r)/2;

            ll x = kp*y;

            if(x<l1) l = y+1;
            else if(x>r1) r = y-1;
            else {
                miny = y;
                r = y-1;
            }
        }

        ll maxy = -1;
        l = l2, r = r2;

        while(l<=r) {
            ll y = (l+r)/2;

            ll x = kp*y;

            if(x<l1) l = y+1;
            else if(x>r1) r = y-1;
            else {
                maxy = y;
                l = y+1;
            }
        }

        if(miny!=-1) {
            ans+=maxy-miny+1;
        }

        kp*=k;
        if(kp>r1) break;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
