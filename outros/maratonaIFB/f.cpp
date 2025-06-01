#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

void dfs(vvi &adj, vb &vis, int v, pii &p) {
    if(vis[v]) return;
    vis[v] = true;
    p.ff++;
    
    for(auto u:adj[v]) {
        p.ss++;
        dfs(adj,vis,u,p);
    }
}

int main() { _
    int n,m;
    cin >> n >> m;

    vvi adj(n+1);
    
    {
    int a,b;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    }

    pii p = {0,0};
    vb v(n+1,false);

    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(v[i]) continue;

        dfs(adj,v,i,p);
        p.ss>>=1;
        if(p.ss==p.ff-1) ans++;
        p = {0,0};
    }

    cout << ans << '\n';

    return 0;
}
