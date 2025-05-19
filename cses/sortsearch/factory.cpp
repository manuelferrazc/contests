#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool check(vector<ll> &v, ll t, ll x) {
    for(ll i:v) {
        t-=x/i;
        if(t<=0) return true;
    }
    return false;
}

int main() { _
    ll n, t;
    cin >> n >> t;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    ll l=1,r=1'000'000'000'000'000'000LL,ans=LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1;

        if(check(v,t,m)) {
            ans = m;
            r=m-1;
        } else l = m+1;
    }

    cout << ans << '\n';

    return 0;
}
