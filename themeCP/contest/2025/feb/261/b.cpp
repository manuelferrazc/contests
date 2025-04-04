#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k,g;
    cin >> n >> k >> g;

    ll x = k*g;
    if(g&1) x-=(n-1)*(g/2);
    else x-=(n-1)*(g/2-1);
    if(x<=0) cout << k*g << '\n';
    else {
        if(x%g>=((g/2)+(g&1))) x+=g-(x%g);
        else x-=x%g;
        cout << k*g-x << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
