#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;
vector<ll> v;

bool check(ll m) {
    ll qtd=0,s=0;
    for(ll i=0;i<n;i++) {
        if(s+v[i]>m) {
            qtd++;
            s=v[i];
        } else s+=v[i];
    }
    return qtd<k;
}

int main() { _
    cin >> n >> k;
    v.resize(n);
    for(auto &i:v) cin >> i;

    ll l=*max_element(v.begin(),v.end()), r = n*(1e9),ans=LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1LL;

        if(check(m)) {
            ans=min(ans,m);
            r=m-1;
        } else l=m+1;
    }

    cout << ans << '\n';

    return 0;
}
