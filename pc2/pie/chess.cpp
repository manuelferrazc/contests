#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

ll fexp(ll n, ll e) {
    ll ret=1;
    while(e) {
        if(e&1) ret = ret*n%mod;
        n = n*n%mod;
        e>>=1;
    }
    return ret;
}



int main() { _

    return 0;
}
