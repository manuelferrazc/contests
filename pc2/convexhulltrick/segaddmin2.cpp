#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q;
    cin >> n >> q;

    ll *v = new ll[20000001];
    for(ll i=0;i<20000001;i++) v[i] = LLONG_MAX;

    while(n--) {
        ll l,r,a,b;
        cin >> l >> r >> a >> b;

        for(ll i=l;i<r;i++) {
            ll pos = i+10000000;
            v[pos] = min(v[pos],a*i+b);
        }
    }

    while(q--) {
        int op;
        cin >> op;

        if(op) {
            ll pos;
            cin >> pos;
            if(v[pos+10000000]==LLONG_MAX) cout << "INFINITY\n";
            else cout << v[pos+10000000] << '\n';
        } else {
            ll l,r,a,b;
            cin >> l >> r >> a >> b;

            for(ll i=l;i<r;i++) {
                ll pos = i+10000000;
                v[pos] = min(v[pos],a*i+b);
            }
        }
    }

    delete[] v;
    return 0;
}
