#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

ll fexp(ll n, ll e) {
    if(e==1) return n;
    
    ll r = fexp(n,e>>1);
    r = (r*r)%mod;
    if(e&1) r = (r*n)%mod;
    return r;
}

int main() { _
    ll n;
    cin >> n;

    cout << fexp(2,n) << '\n';
    
    return 0;
}
