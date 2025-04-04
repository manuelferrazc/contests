#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define l first
#define r second
typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<pair<int,int>> &adj, vector<int> &dp, string &s, int v=0) {
    auto &sla = adj[v];
    if(sla.l>=0) {
        dfs(adj,dp,s,sla.l);
        dp[v] = dp[sla.l] + (s[v]!='L');
        if(sla.r>=0) {
            dfs(adj,dp,s,sla.r);
            dp[v] = min(dp[v],dp[sla.r]+(s[v]!='R'));
        }
    } else if(sla.r>=0) {
        dfs(adj,dp,s,sla.r);
        dp[v] = dp[sla.r] + (s[v]!='R');
    }
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<pair<int,int>> adj(n);
    for(auto &i:adj) {
        cin >> i.l >> i.r;
        i.l--;
        i.r--;
    }

    vector<int> dp(n,0);
    dfs(adj,dp,s);

    cout << dp.front() << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
