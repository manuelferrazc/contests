#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353LL;

ll fexp(ll n, ll e) {
    if(e==1) return n;
    if(e==0) return 1;

    ll r= fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;
    return r;
}

int main() { _
    int n;
    string s;
    cin >> n >> s;

    int o=0;
    for(char c:s) if(c=='1') o++;

    cout << fexp(2,2*n)  << '\n';
    return 0;
}
