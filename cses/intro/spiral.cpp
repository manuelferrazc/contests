#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,y;
    cin >> x >> y;
    ll p = max(x-1,y-1)*max(x-1,y-1);
    if(max(x,y)&1) {
        if(x>=y) cout << p+y << '\n';
        else cout << p+2*y-x << '\n';
    } else {
        if(y>=x) cout << p+x << '\n';
        else cout << p+2*x-y << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
