#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

int main() { _
    ll n,m;
    cin >> n >> m;
    vector<ll> v(n),dp(m,0);
    for(ll &i:v) cin >> i;

    if(v[0]) dp[v[0]-1]++;
    else for(ll &i:dp) i++;

    for(ll b=1;b<n;b++) {
        ll i = v[b];
        vector<ll> aux(m,0);
        if(i) {
            i--;
            for(ll j=max(i-1,0LL);j<=min(m-1,i+1);j++) aux[i]+=dp[j];
            aux[i]%=mod;
            dp = aux;
            continue;
        }
        for(ll j=0;j<m;j++) {
            for(ll k=max(j-1,0LL);k<=min(m-1,j+1);k++) aux[j]+=dp[k];
            aux[j]%=mod;
        }
        dp = aux;
    }

    cout << accumulate(dp.begin(),dp.end(),0LL)%mod << '\n';

    return 0;
}
