#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,x,p;
bool check(ll nn) {
    ll l=1,r=p;

    while(l<=r) {
        ll m=(l+r)>>1;
        ll a = m*(m+1)/2+x;
        if(a==nn) return true;
        else if(a<nn) l=m+1;
        else r=m-1;
    }

    return false;
}

void solve() {
    cin >> n >> x >> p;

    for(ll i=1;i<=2*n;i++) {
        if(check(n*i)) {
            cout << "yES\n";
            return;
        }
    }

    cout << "nO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
