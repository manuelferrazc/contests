#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1000000007;

ll fexp(ll n, ll e) {
    if(e==1) return n;
    if(e==0) return 1;

    ll ret = fexp(n,e/2)%mod;
    ret = (ret*ret)%mod;
    if(e&1) ret = (ret*n)%mod;

    return ret;
}

int main() { _
    ll n;
    cin >> n;
    ll ans = fexp(26,n);

    for(ll i=1;i<=n-16) {
        ll x = fexp(n-i-16,m-2)*fexp(i)
    }
    return 0;
}
