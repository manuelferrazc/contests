#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

// vector<int> price,page;
// vector<vector<int>> dp;

// int ddp(int i, int c) {
    //     if(i<0 or c==0) return 0;
    //     if(dp[i][c]!=-1) return dp[i][c];
    
//     dp[i][c] = ddp(i-1,c);
//     if(price[i]<=c) dp[i][c] = max(dp[i][c],ddp(i-1,c-price[i])+page[i]);
//     return dp[i][c];
// }

int main() { 
    ll n,x;
    cin >> n >> x;
    
    vector<int> price(n), page(n);
    for(int &i:price) cin >> i;
    for(int &i:page) cin >> i;

    vector<vector<int>> dp(n,vector<int>(x+1));

    for(int j=0;j<=x;j++) {
        if(price[0]<=j) dp[0][j] = page[0];
        else dp[0][j] = 0;
    }

    for(int i=1;i<n;i++) {
        for(int j=0;j<=x;j++) {
            if(price[i]<=j) dp[i][j] = max(dp[i-1][j],dp[i-1][j-price[i]]+page[i]);
            else dp[i][j] = dp[i-1][j];
        }
    }

    cout << dp[n-1][x] << '\n';
    return 0;
}
