#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string a,b;
vector<vector<int>> dp;

int ddp(int i, int j) {
    if(dp[i][j]!=INT_MAX) return dp[i][j];
    if(i==0) return dp[i][j] = j;
    if(j==0) return dp[i][j] = i;

    dp[i][j] = min({ddp(i,j-1)+1,ddp(i-1,j)+1,ddp(i-1,j-1)+1});
    if(a[i-1]==b[j-1]) dp[i][j] = min(dp[i][j],ddp(i-1,j-1));
    return dp[i][j];
}

int main() { _
    cin >> a >> b;
    int n = a.size(), m = b.size();

    dp.resize(n+1,vector<int>(m+1,INT_MAX));
    cout << ddp(n,m) << '\n';

    return 0;
}
