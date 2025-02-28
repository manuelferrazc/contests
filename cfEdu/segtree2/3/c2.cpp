#include <bits/stdc++.h> 

using namespace std;
typedef long long ll;

int main() {
    ll n,m,op;
    cin >> n >> m;
    vector<ll> v(n,0);

    while(m--) {
        cin >> op;

        if(op==1LL) {
            ll l,r,x;
            cin >> l >> r >> x;
            for(;l<r;l++) v[l]+=x;           
        } else {
            ll x,l;
            cin >> x >> l;
            bool f=true;
            for(;l<n;l++) {
                if(v[l]>=x) {
                    cout << l << '\n';
                    f=false;
                    break;
                }
            }
            if(f) cout << "-1\n";
        }
    }
}