#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dfs(vector<vector<int>> &adj, vector<int> &dp, int v) {
    if(dp[v]!=-1) return dp[v];
    if(adj[v].empty()) return dp[v] = 0;

    for(auto i:adj[v]) dp[v] = max(dp[v],dfs(adj,dp,i));
    return ++dp[v];
}

int main() { _
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<bool> r(n,true);
    vector<int> dp(n,-1);

    while(m--) {
        int a,b;
        cin >> a >> b;
        a--;b--;
        r[b] = false;
        adj[a].push_back(b);
    }

    int ans=0;
    for(int i=0;i<n;i++) if(r[i]) ans = max(ans,dfs(adj,dp,i));
    cout << ans << '\n';
    
    return 0;
}
