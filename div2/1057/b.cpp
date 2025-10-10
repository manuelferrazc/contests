#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,y,z;
    cin >> x >> y >> z;

    ll a=0,b=0,c=0;

    for(int i=0;i<33;i++) {
        if(x&(1LL<<i)) {
            a|=(1LL<<i);
            b|=(1LL<<i);
        }

        if(y&(1LL<<i)) {
            b|=(1LL<<i);
            c|=(1LL<<i);
        }

        if(z&(1LL<<i)) {
            a|=(1LL<<i);
            c|=(1LL<<i);
        }
    }

    if(((a&b)!=x) or ((b&c)!=y) or ((a&c)!=z)) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
