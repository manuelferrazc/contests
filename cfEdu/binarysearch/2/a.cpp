#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,w,h;
    cin >> w >> h >> n;

    ll l = 1,r=max(h,w)*(sqrt(n)+1LL), ans = LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1;
        ll line = m/w;
        if(line*(m/h)>=n) {
            ans = min(ans,m);
            r=m-1;
        } else l = m+1;
    }
    cout << ans << '\n';

    return 0;
}
