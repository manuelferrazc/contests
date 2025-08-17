#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1 ? r*n%mod : r;
}

int main() { _
    ll mx = 2e6+1;
    ll *v = (ll*)malloc(sizeof(ll)*mx);
    v[0] = 1;
    for(ll i=1;i<mx;i++) v[i] = i*v[i-1]%mod;

    ll n,m;
    cin >> n >> m;

    cout << v[n+m-1]*fexp(v[n-1],mod-2)%mod*fexp(v[m],mod-2)%mod << '\n';

    free(v);
    return 0;
}
