#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool dfs(vector<int> *adj, int *color, int v, int p, int *q) {
    q[color[v]]++;

    bool ret = false;
    for(auto u:adj[v]) {
        if(u==p) continue;
        if(color[u]==color[v]) ret = true;
        else if(color[u]==-1) {
            color[u] = 1-color[v];
            if(dfs(adj,color,u,v,q)) ret = true;
        }
    }

    return ret;
}

void solve() {
    int n,m;
    cin >> n >> m;

    vector<int> adj[n];
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int color[n];
    int ans = 0;

    for(int i=0;i<n;i++) color[i] = -1;

    for(int i=0;i<n;i++) {
        if(color[i]!=-1) continue;
        color[i] = 0;

        int c[2];
        c[0] = c[1] = 0;
        if(dfs(adj,color,i,-1,c)==false) ans+=max(c[0],c[1]);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
