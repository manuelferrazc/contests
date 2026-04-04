#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool vis[5001];
ll dist[5001];

void no() {
    cout << "NO\n";
    exit(0);
}

void dfs(vector<pair<int,ll>> *adj, int v) {
    vis[v] = true;
    for(auto [u,c]:adj[v]) {
        if(vis[u]==false) {
            dist[u] = dist[v]+c;
            dfs(adj,u);
        }

        if(dist[u]!=dist[v]+c) no();
    }
}

int main() { _
    int n,m;
    cin >> n >> m;

    vector<pair<int,ll>> adj[n+1];

    for(int i=0;i<m;i++) {
        int l,r,s;
        cin >> l >> r >> s;

        adj[r].push_back(pair(l-1,-s));
        adj[l-1].push_back(pair(r,s));
    }

    for(int i=1;i<=n;i++) {
        if(not vis[i]) dfs(adj,i);
    }

    cout << "YES\n";
    for(int i=1;i<=n;i++) cout << dist[i]-dist[i-1] << ' ';
    cout << '\n';

    return 0;
}
