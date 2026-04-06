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
    ll dp[n][n];
    
    for(int i=0;i<n;i++) {
        cin >> v[i];
        dp[i][i] = v[i];
    }

    if(n%2==0) for(int i=0;i<n;i++) dp[i][i]*=-1;

    for(int l = 2;l<=n;l++) {
        bool p = (l&1)==(n&1); // 1 se for vez do primeiro 

        for(int i=0;i+l<=n;i++) {
            if(p) dp[i][i+l-1] = max(dp[i][i+l-2]+v[i+l-1],v[i]+dp[i+1][i+l-1]);
            else dp[i][i+l-1] = min(dp[i][i+l-2]-v[i+l-1],-v[i]+dp[i+1][i+l-1]);
        }
    }

    cout << dp[0][n-1] << '\n';

    return 0;
}
