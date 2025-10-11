#include <bits/stdc++.h>

// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")

using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
vector<ll> v;
vector<int> dp;
ll x,n,count[1<<20];
 
 
int ddp(int m) {
    if(dp[m]!=INT_MAX) return dp[m];
 
    int sla=28;
    for(;(m&(1<<sla))==0;sla--) {}
    for(int i=m;i&(1<<sla);i=(i-1)&m) {
        if(::count[i]<=x) dp[m] = min(dp[m],1+ddp(m-i));
    }
 
    return dp[m];
}
 
int main() { _
    cin >> n >> x;
    v.resize(n);
    dp.resize(1<<n,INT_MAX);
    dp[0] = 0;
    for(ll &i:v) cin >> i;
 
    for(int i=0;i<(1<<n);i++) {
        ::count[i] = 0;
        for(int j=0;j<n;j++) {
            if(i&(1<<j)) ::count[i]+=v[j];
        }
    }
 
    cout << ddp((1<<n)-1) << '\n';
 
    return 0;
}