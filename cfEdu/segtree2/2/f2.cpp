#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n,m,op,l,r,x;
    cin >> n >> m;

    vector<ll> v(n,0LL);

    while(m--) {
        cin >> op >> l >> r;

        if(op==1) {
            cin >> x;
            for(ll i=l;i<r;i++) v[i]=x;
        } else {
            ll ans = 0;
            for(ll i=l;i<r;i++) ans+=v[i];
            cout << ans << '\n';
        }
    }
    return 0;
}