#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

double dp[2'000'001][21]; // prob
bool vis[2'000'001][21];

double dfs(int nlim, int n, int x) {
    if(n<=0 or n>=nlim) return 0;
    if(vis[n][x]) return dp[n][x];
    vis[n][x] = 1;
    
    return dp[n][x] = dfs(nlim,n+(1<<x),0)/2+dfs(nlim,n-(1<<x),x+1)/2+1;
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<2'000'001;i++) for(int j=0;j<21;j++) {
        dp[i][j] = 0;
        vis[i][j] = 0;
    }

    dfs(n+n,n,0);
    
    cout << fixed << setprecision(10) << dfs(n+n,n,0) << '\n';
    return 0;
}
