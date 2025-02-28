#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll count(ll n, ll sigma, ll x) {
    ll l=1,r=n,ret=0;
    while(l<=r) {
        ll m = (l+r)>>1;
        if(m*sigma<x) {
            ret = max(ret,m);
            l=m+1;
        } else r=m-1;
    }
    return ret;
}

bool check(ll n, ll k, ll x) {
    ll r=0;
    for(ll i=1;i<=n;i++) 
        r+=count(n,i,x);

    return r<k;
}

int main() { _
    ll n,k;
    cin >> n >> k;

    ll l=1, r=n*n, ans=LLONG_MIN;

    while(l<=r) {
        ll m = (l+r)>>1;

        if(check(n,k,m)) {
            ans=max(ans,m);
            l=m+1;
        } else r=m-1;
    }

    cout << ans << '\n';

    return 0;
}
        