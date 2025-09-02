#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1e9+7;

int main() { _
    ll n,l,r;
    cin >> n >> l >> r;

    ll q0 = r/3-(l-1)/3;
    ll q1 = (r+2)/3-(l+1)/3;
    ll q2 = (r+1)/3-(l)/3;

    // cout << q0 << ' ' << q1 << ' ' << q2 << '\n';

    ll dp[n][3];

    dp[0][0] = q0;
    dp[0][1] = q1;
    dp[0][2] = q2;

    for(int i=1;i<n;i++) {
        dp[i][0] = dp[i-1][0]*q0+dp[i-1][1]*q2+dp[i-1][2]*q1;
        dp[i][0]%=mod;

        dp[i][1] = dp[i-1][0]*q1+dp[i-1][1]*q0+dp[i-1][2]*q2;
        dp[i][1]%=mod;

        dp[i][2] = dp[i-1][0]*q2+dp[i-1][1]*q1+dp[i-1][2]*q0;
        dp[i][2]%=mod;
    }

    cout << dp[n-1][0] << '\n';

    return 0;
}
