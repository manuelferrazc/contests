#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool check(vector<ll> &v, ll k, ll x) {
    ll s=0;
    for(ll i:v) {
        if(s+i>x) {
            s=0;
            k--;
        }
        s+=i;
    }

    return k>0;
}

int main() { _
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    ll l=*max_element(v.begin(),v.end()),r=300'000'000'000'000LL, ans = LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1;

        if(check(v,k,m)) {
            ans = m;
            r=m-1;
        } else l=m+1;
    }

    cout << ans << '\n';

    return 0;
}
