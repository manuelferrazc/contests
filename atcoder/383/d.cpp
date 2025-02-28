#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll exp(ll x) {
    ll r=1;
    for(int i=0;i<8;i++) {r*=x;if(r<0) return LLONG_MAX;}
    return r;
}

int main() { _
    ll n;
    cin >> n;

    vector<ll> p;
    ll s = sqrt(n);
    vector<bool> c(s,true);
    for(ll i=2;i<s;i++) {
        if(not c[i]) continue;
        p.push_back(i);
        for(ll j=i+i;j<s;j+=i) {
            c[j] = false;
        }
    }

    ll ans=0;

    for(ull i=0;i<p.size();i++) {
        ll act = p[i]*p[i];

        if(act>=n) break;
        for(ull j=i+1;j<p.size();j++) {
            ll act1 = act*p[j];
            if(act1>=n) break;
            if(act*p[j]*p[j]<=n) ans++;
            else break;
        }
    }

    for(ull i=0;i<p.size();i++) {
        if(exp(p[i])<=n) ans++;
        else break;
    }

    cout << ans << '\n';

    return 0;
}
