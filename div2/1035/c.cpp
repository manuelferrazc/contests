#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,l,r,k;
    cin >> n >> l >> r >> k;

    if(n&1) cout << l << '\n';
    else if(l==r or n==2) cout << -1 << '\n';
    else {
        for(ll i=62;i>=0;i--) {
            if(r&(1LL<<i)) {
                if(l&(1LL<<i)) {
                    cout << "-1\n";
                    return;
                }
                break;
            }
        }

        if(k<=n-2) cout << l << '\n';
        else {
            for(ll i=0;;i++) {
                if((1LL<<i)>l) {
                    cout << (1LL<<i) << '\n';
                    return;
                }
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
