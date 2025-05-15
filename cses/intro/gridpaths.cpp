#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    string s;
    cin >> s;
    
    vector<vector<vector<ull>>> dp(7,vector<vector<ull>>(7,vector<ull>(48,0)));
    if(s.back()=='D' or s.back()=='?') dp[5][6][47] = 1;
    if(s.back()=='L' or s.back()=='?') dp[6][5][47] = 1;

    for(int t = 46;t>=0;t--) {
        for(int x=0;x<7;x++) {
            for(int y=0;y<7;y++) {
                if(s[t]=='U') {
                    if(x) dp[x][y][t] = dp[x-1][y][t+1];
                } else if(s[t]=='D') {
                    if(x!=6) dp[x][y][t] = dp[x+1][y][t+1];
                } else if(s[t]=='L') {
                    if(y) dp[x][y][t] = dp[x][y-1][t+1];
                } else if(s[t]=='R') {
                    if(y!=6) dp[x][y][t] = dp[x][y+1][t+1];
                } else {
                    if(x) dp[x][y][t] += dp[x-1][y][t+1];
                    if(x!=6) dp[x][y][t] += dp[x+1][y][t+1];
                    if(y) dp[x][y][t] += dp[x][y-1][t+1];
                    if(y!=6) dp[x][y][t] += dp[x][y+1][t+1];
                }
            }
        }
    }
    

    cout << dp[0][0][0] << '\n';
    
    return 0;
}
