#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v;
vector<int> dp;
ll x,n,count[1<<20];
ll b[1<<20];


int ddp(int m) {
    if(dp[m]!=INT_MAX) return dp[m];

    for(int i=m;i&(1<<b[m]);i=(i-1)&m) {
        if(::count[i]<=x) dp[m] = min(dp[m],1+ddp(m-i));
    }

    return dp[m];
}

int main() { 
    cin >> n >> x;
    v.resize(n);
    dp.resize(1<<n,INT_MAX);
    dp[0] = 0;
    for(ll &i:v) cin >> i;

    for(int i=0;i<(1<<n);i++) {
        ::count[i] = 0;
        b[i] = 0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) {
                b[i] = j;
                ::count[i]+=v[j];
            }
        }
    }

    cout << ddp((1<<n)-1) << '\n';

    return 0;
}
