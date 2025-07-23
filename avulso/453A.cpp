#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

double fexp(double x, ll e) {
    if(e==1) return x;

    double r = fexp(x,e>>1);
    r*=r;
    if(e&1) r*=x;
    return r;
}

void solve() {
    ll m,n;
    cin >> m >> n;

    double ans=0;
    for(ll x=1;x<=m;x++) {
        ans+=x*(fexp((double)x/m,n)-fexp((double)(x-1)/m,n));
    }

    cout << fixed << setprecision(13);
    cout << ans << '\n';
}

int main() { _
    // int t;
    // cin >> t;
    // while(t--) 
    solve();
    return 0;
}
