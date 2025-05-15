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
    string s;
    cin >> s;
    s = 'a' + s;
    // 0 pedra, 1, tesoura, 2 papel
    vector<vector<int>> dp(n+1,vector<int>(3,0));
    
    for(int i=1;i<=n;i++) {
        if(s[i]=='R') {
            dp[i][0] = max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = -1;
            dp[i][2] = 1+max(dp[i-1][0],dp[i-1][1]);
        } else if(s[i]=='S') {
            dp[i][0] = 1+max(dp[i-1][1],dp[i-1][2]);
            dp[i][1] = max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = -1;
        } else {
            dp[i][0] = -1;
            dp[i][1] = 1+max(dp[i-1][0],dp[i-1][2]);
            dp[i][2] = max(dp[i-1][0],dp[i-1][1]);
        }
    }

    cout << *max_element(dp.back().begin(),dp.back().end()) << '\n';

    return 0;
}
