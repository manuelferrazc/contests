#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;

    int v[n][m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin >> v[i][j];

    if(n==1) {
        int ans = INT_MAX;

        for(int i=1;i<m;i++) ans = min(ans,abs(v[0][i]-v[0][i-1]));

        cout << ans << '\n';
        return 0;
    } else if(n==2) {
        int ans1 = INT_MAX;
        
        for(int i=0;i<m;i++) 
            ans1 = min(ans1,abs(v[0][i]-v[1][i]));
        
        int ans2 = ans1;
        for(int i=1;i<m;i++) {
            ans1 = min(ans1,abs(v[1][i-1]-v[0][i]));
            ans2 = min(ans2,abs(v[0][i-1]-v[1][i]));
        }

        cout << max(ans1,ans2) << '\n';
        return 0;
    }


    int best[16][16];
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {

            best[i][j] = INT_MAX;
            for(int k=0;k<m;k++) best[i][j] = min(best[i][j],abs(v[i][k]-v[j][k]));

            best[j][i] = best[i][j];
        }
    }

    int best2[n][n];

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) continue;

            best2[i][j] = INT_MAX; // comecando com a i, terminando com a j
            for(int k=1;k<m;k++) best2[i][j] = min(best2[i][j],abs(v[i][k]-v[j][k-1]));

        }
    }

    int ans = INT_MIN;

    int pot = 1<<n;

    for(int fir=0;fir<n;fir++) {
        vector<vector<int>> dp(pot,vector<int>(n,-1));
        for(int i=0;i<n;i++) dp[1<<i][i] = INT_MIN;
        dp[1<<fir][fir] = INT_MAX;


        auto ddp = [&] (auto f, int mask, int i) -> int {
            if(dp[mask][i]!=-1) return dp[mask][i];

            dp[mask][i] = INT_MIN;
            for(int j=0;j<n;j++) {
                if((mask&(1<<j)) and i!=j) {
                    dp[mask][i] = max(dp[mask][i],min(best[i][j],f(f,mask-(1<<i),j)));
                }
            }

            return dp[mask][i];
        };

        for(int i=0;i<n;i++) {
            if(i==fir) continue;

            ans = max(ans,min(ddp(ddp,pot-1,i),best2[fir][i]));
        }
    }

    cout << ans << '\n';


    return 0;
}
