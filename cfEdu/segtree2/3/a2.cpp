#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n,m;
    cin >> n >> m;

    vector<ll> v(n,0);
    while(m--) {
        ll l,r,x;
        cin >> l >> r >> x;
        for(;l<r;l++) v[l] = x;

        ll max=0, act=0;
        for(ll i=0;i<n;i++) {
            act+=v[i];
            if(act<0) act=0;
            max = ::max(max,act);
        }
        cout << max << '\n';
    }
}