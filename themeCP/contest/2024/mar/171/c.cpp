#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    vector<ll> v;

    ll i;
    for(i=0;;i++) if(n&(1LL<<i)) {
        v.push_back(1LL<<i);
        break;
    }

    for(i=i+1;i<62;i++) {
        if((1LL<<i)&n) {
            ll s=v.size();
            v.push_back(1LL<<i);
            for(ll j=0;j<s;j++) v.push_back(v[j]+v[s]);
        }
    }

    cout << v.size() << '\n';
    for(auto j:v) cout << j << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
