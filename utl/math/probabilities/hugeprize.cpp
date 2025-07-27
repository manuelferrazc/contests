#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() {  // idk this doesn't work
    int n,l,k;
    cin >> n >> l >> k;

    vector<pair<int, double>> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].ss;
        v[i].ss*=0.01;
    }
    for(int i=0;i<n;i++) cin >> v[i].ff;

    sort(v.begin(),v.end());

    vector<vector<vector<double>>> dp(n+1,vector<vector<double>>(40201,vector<double>(n+1,0.0)));

    for(int i=0;i<201;i++) dp[0][i][0] = 1;

    for(int i=1;i<=n;i++) { // i is the item
        for(int j=0;j<40201;j++) { // j is the current capacity
            for(int k=0;k<=n;k++) { // k is how many times i must win
                if(k==0)
                    dp[i][j][k] = (1-v[i-1].ss)*dp[i-1][j][k];
                else if(v[i-1].ff>0) {
                    if(j+v[i-1].ff>40200) continue;
                    dp[i][j][k] = dp[i-1][j+v[i-1].ff][k-1]*v[i-1].ss + dp[i-1][j][k]*(1-v[i-1].ss);
                }
                else if(j==0) 
                    dp[i][j][k] = dp[i-1][j][k]*(1-v[i-1].ss);
                else 
                    dp[i][j][k] = dp[i-1][j-1][k-1]*v[i-1].ss + dp[i-1][j][k]*(1-v[i-1].ss);
            }
        }
    }
    
    double ans=0;
    for(int i=l;i<=n;i++) ans+=dp[n][l][i];

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
