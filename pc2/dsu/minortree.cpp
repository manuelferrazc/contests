#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> adj[200'000];
bool vis[200'000];
int qtd;

void dfs(int v, int ans) {
    vis[v] = true;
    qtd++;

    for(auto [u,w]:adj[v]) {
        if(vis[u] or ((ans|w)>ans)) continue;
        dfs(u,ans);
    }
}

void solve() {
    int n,m;
    cin >> n >> m;
    
    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=0;i<m;i++) {
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int ans = (1<<30)-1;

    for(int i=29;i>=0;i--) {
        ans-=(1<<i);
        for(int j=0;j<n;j++) vis[j] = false;
        qtd = 0;

        dfs(0,ans);
        if(qtd!=n) ans+=(1<<i);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
