#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n;
    cin >> n;

    vector<ll> dp(n+1,INT_MAX);
    dp[0] = 0;
    for(ll i=1;i<=n;i++) {
        ll m = i;
        while(m) {
            dp[i] = min(dp[i],1+dp[i-m%10]);
            m/=10;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
