#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll m = 998244353;

void solve() {
    ll x=1,b;
    int q; cin >> q;
    int t;
    while(q--) {
        cin >> t;
        if(t==3) cout << t%m << '\n';
        else if(t==1) {
            cin >> b;
            x*=10;
            x+=b;
            if(x>=1'000'000'000LL)
        }
    }
}

int main() { _
    solve();
    return 0;
}
