#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,x;
    cin >> n >> x;

    ll q=0;
    for(ll i=0;i<40;i++) if(x&(1LL<<i)) q++;

    ll m=0;
    while(x&(1LL<<m)) m++;

    if(n==1 and x==0) cout << -1 << '\n';
    else if(n==1) cout << x << '\n';
    else if(x==0) {
        if(n&1) cout << n-1LL+4LL << '\n';
        else cout << n << '\n';
    } else if(q>=n) cout << x << '\n';
    else {
        if((n-q)&1LL) {
            if(q>1) cout << x+n-q+1 << '\n';
            else cout << x+n-q-1+2*(1LL<<m) << '\n';
        } else cout << x+n-q << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
