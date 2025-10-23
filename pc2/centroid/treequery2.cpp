#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<pair<int,ll>>> adj;

int ans;
ll w;

void dfs(int v, int p, ll w2) {
    if(w2>w) return;
    ans++;

    for(auto[u,wp]:adj[v]) {
        if(u!=p) dfs(u,v,w2+wp);
    }
}

int main() { _
    int n,q;
    cin >> n >> q;

    adj.resize(n);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    while(q--) {
        cin >> n >> w;
        ans=0;
        dfs(n-1,-1,0);
        cout << ans << '\n';
    }

    return 0;
}
