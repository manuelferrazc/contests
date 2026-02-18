#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    pair<ll,ll> v[n];
    for(int i=n-1;i>=0;i--) cin >> v[i].x >> v[i].y;

    ll l = 1, r = 1'999'999'999;

    for(int i=1;i<n;i++) {
        ll dist = abs(v[i].x-v[i-1].x)+abs(v[i].y-v[i-1].y);

        if(l>=dist) {
            cout << -1 << '\n';
            return 0;
        }

        ll r2 = dist-l;

        l = max(dist-r,1ll);
        r = r2;
    }

    cout << r << '\n';

    return 0;
}
