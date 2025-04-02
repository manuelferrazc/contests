#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void dfs(vector<vector<int>> &adj, vector<bool> &vis, int v) {
    vis[v] = true;

    for(auto i:adj[v]) {
        if(vis[i]) continue;
        dfs(adj,vis,i);
    }
}

int main() { _
    int n,m;
    cin >> n >> m;

    int c=0;
    vector<vector<int>> adj(n);
    vector<bool> v(n,false);

    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[b].push_back(a);
        adj[a].push_back(b);
    }

    for(int i=0;i<n;i++) {
        if(v[i]) continue;
        c++;
        dfs(adj,v,i);
    }

    cout << m-(n-c) << '\n';

    return 0;
}
