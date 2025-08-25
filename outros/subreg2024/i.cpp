#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll max = 1'000'000;
const ll mod = 1e9+7;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    ll r = fexp(n*n%mod,e>>1);
    return e&1 ? r*n%mod : r;
}

// void fat(vector<ll>)

int main() { _
    vector<int> c(max+1);
    iota(c.begin(),c.end(),0);
    vector<bool> prime(max+1,false);

    for(int i=2;i<=max;i++) {
        if(c[i]!=i) continue;
        prime[i] = true;
        for(int j=i+i;j<=max;j+=i) c[j] = i;
    }



    return 0;
}
