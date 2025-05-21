#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

int main() { _
    ll n;
    cin >> n;
    vector<ll> dp(n+5);
    
    for(ll i=0;i<6;i++) {
        dp[i] = 1;
        for(ll j=i-1;j>=0;j--) dp[i]+=dp[j];
    }

    for(ll i=6;i<n;i++) {
        dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])%mod;
    }

    cout << dp[n-1] << '\n';

    return 0;
}
