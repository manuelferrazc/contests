#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll t1(ll n) {
    ll l=0,r=3e9;
    ll x=LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1;
        if(4*m*m>=n) {
            x=min(x,m);
            r=m-1;
        } else l=m+1;
    }
    return 2*x-1;
}

ll t2(ll n) {
    ll l=0,r=3e9;
    ll x= LLONG_MAX;

    n--;
    while(l<=r) {
        ll m = (l+r)>>1;
        
        if(4*(m+1)*m>=n) {
            x=min(x,m);
            r=m-1;
        } else l=m+1;
    }

    return 2*x;
}

void solve() {
    ll n;
    cin >> n;
    cout << min(t1(n),t2(n)) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
