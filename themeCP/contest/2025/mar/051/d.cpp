#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;

    for(ll i=0;;i++) {
        ll c=n/2;
        if(n&1) c++;
        n>>=1;
        if(c>=k) {
            cout << ((1LL<<i))*(2*k-1) << '\n';
            return;
        }
        else k-=c;
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
