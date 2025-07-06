#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll ans(vector<ll> &v) {
    ll r=0,m=LLONG_MAX;
    for(ll &i:v)  {
        m = min(m,i);
        r+=m;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    ll an = ans(v);
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            ll a=v[i],b = v[j];
            v[i]+=v[j];
            v[j] = 0;
            an = min(an,ans(v));
            v[i] = a;
            v[j] = b;
        }
    }
    cout << an << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
