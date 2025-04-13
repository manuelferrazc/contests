#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v;
ll n,k;

bool solve(ll t,ll q) {
    for(ull i=0;i<k;i++) {
        if(v[i]>=t) continue;
        q-=t-v[i];
        if(q<0) return false;
    }
    return true;
}

int main() { 
    cin >> n >> k;
    
    v.resize(n);
    for(ll &i:v) cin >> i;

    sort(v.rbegin(),v.rend());

    ll ans = v[k-1];
    for(ll i=0;i<k;i++) v[i]-=v[k-1];

    ll s=0;
    for(ll i=k;i<n;i++) s+=v[i];
    ll l=0,r=3e17,a=0;
    while(l<=r) {
        ll m = (l+r)>>1;
        if(solve(m,s)) {
            l=m+1;
            a=m;
        } else r=m-1;
    }

    cout << ans+a << '\n';
    return 0;
}
