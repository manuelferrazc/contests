#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define l first
#define r second
typedef long long ll;
typedef unsigned long long ull;

bool check(vector<pair<ll,ll>> &v, ll x, ll k) {
    ll t=0;
    for(auto i:v) 
        if(x>=i.l) t+=min(x,i.r+1)-i.l; 
    return t<=k;
}

int main() { _
    ll n,k;
    cin >> n >> k;

    vector<pair<ll,ll>> v(n);
    for(auto &i:v) cin >> i.l >> i.r;

    ll l=INT_MIN,r=INT_MAX,ans=LLONG_MIN;

    while(l<=r) {
        ll m = (l+r)>>1;
        if(check(v,m,k)) {
            ans = max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';

    return 0;
}
