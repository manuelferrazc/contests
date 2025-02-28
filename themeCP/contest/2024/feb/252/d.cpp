#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<ll,ll> count(ll x, ll m) {
    ll l=1,r=x,ret=LLONG_MAX;
    while(l<=r) {
        ll mm = (l+r)>>1;
        if(((x%mm!=0)+x/mm)<=m) {
            ret = min(ret,mm);
            r=mm-1;
        } else l=mm+1;
    }

    return {ret,x/ret};
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;

    ll max = v.back();

    ll ans=0;
    for(int i=n-2;i>=0;i--) {
        if(v[i]>max) {
            auto p = count(v[i],max);
            ans+=p.first-1;
            max = p.second;
        } else max = v[i];
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
