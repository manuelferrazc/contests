#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m,t;
vector<vector<pair<int,ll>>> adj;
vector<map<int,pair<ll,vector<int>>>> dp;

void dfs(int v=0) {
    if(dp[v].size()) return;
    // cout << "ababa\n";
    for(auto [u,w] : adj[v]) {
        dfs(u);
        for(auto &sla:dp[u]) {
            if(sla.second.first+w>t) continue;
            if(dp[v].count(sla.ff+1)) {
                if(dp[v][sla.ff+1].ff>sla.ss.ff+w) {
                    dp[v][sla.ff+1].ff = sla.ss.ff+w;
                    dp[v][sla.ff+1].ss = sla.ss.ss;
                    dp[v][sla.ff+1].ss.push_back(v);
                }
            } else {
                dp[v].insert(make_pair(sla.ff+1,make_pair(sla.ss.ff+w,sla.ss.ss)));
                dp[v][sla.ff+1].ss.push_back(v);
            }
        }
    }
    // cout << v << ' ' << dp[v].size() << '\n';
}

int main() { 
    cin >> n >> m >> t;
    adj.resize(n);
    dp.resize(n);
    dp.back().insert(make_pair(1,make_pair(0,vector<int>(1,n-1))));

    for(int i=0;i<m;i++) {
        int a,b;
        ll c;
        cin >> a >> b >> c;
        adj[a-1].push_back(make_pair(b-1,c));
    }

    dfs();

    auto it = prev(dp[0].end());
    cout << it->ff << '\n';
    for(auto it2 = it->ss.ss.rbegin();it2!=it->ss.ss.rend();it2++) cout << (*it2)+1 << ' ';
    cout << '\n';

    return 0;
}
