#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x, xo, m, ans=0;
    cin >> x >> m;
    ll b = 0;
    while((1LL<<b)<=x) b++;
    for(ll y=1;y<=(1LL<<b) and y<=m;y++) {
        xo = x^y;
        if(xo and (y%xo==0 or x%xo==0)) ans++;
    }
    cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
