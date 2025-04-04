#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,p;
    cin >> n >> p;
    ll ans=0;
    n%=p;

    ll c=0;
    while(n) {
        ans+=n;
        n<<=1;
        n%=p;
        c++;
        if(c==500) {
            cout << -1 << '\n';
            return;
        }
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
