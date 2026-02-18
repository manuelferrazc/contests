#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    int dp[n][n][2];
    for(int i=0;i<n;i++) dp[i][i][0] = dp[i][i][1] = v[i];

    for(int i=n-1;i>=0;i--) {
        for(int j=i+1;j<n;j++) {
            dp[i][j][0] = max(dp[i+1][j][1],dp[i][j-1][1]);
            dp[i][j][1] = min(dp[i+1][j][0],dp[i][j-1][0]);
        }
    }

    for(int k=0;k<n;k++) {
        int qtd = n-k;
        int ans = -1;
        for(int i=0;i+qtd<=n;i++) {
            ans = max(ans,dp[i][i+qtd-1][0]);
        }

        cout << ans << ' ';
    }
    cout << '\n';

    return 0;
}
