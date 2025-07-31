#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> ans;
void dfs1(vector<vector<pair<ll,ll>>> &adj, vector<bool> &vis, int &mx, int &mi, int v) {
    vis[v] = true;
    mx = max(mx,v);
    mi = min(mi,v);

    for(auto [u,i]:adj[v]) {
        if(vis[u]) continue;
        dfs1(adj,vis,mx,mi,u);
    }
}

bool dfs2(vector<vector<pair<ll,ll>>> &adj, vector<bool> &vis, int mx, int v) {
    if(v==mx) return true;
    vis[v] = true;

    for(auto [u,i]:adj[v]) {
        if(vis[u]) continue;
        if(dfs2(adj,vis,mx,u)) {
            ans.push_back(i);
            return true;
        }
    }

    return false;
}

void solve() {
    ll n;
    cin >> n;
    ans.clear();

    vector<vector<pair<ll,ll>>> adj(2*n);

    for(ll i=0;i<n;i++) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back({b,i+1});
        adj[b].push_back({a,i+1});
    }

    vector<bool> vis(2*n,false),vis2(2*n,false);

    for(int i=0;i<2*n;i++) {
        if(vis[i]) continue;
        int s=i,e=i;
        dfs1(adj,vis,e,s,i);
        if(s!=e) dfs2(adj,vis2,e,s) ;
    }

    cout << ans.size() << '\n';
    sort(ans.begin(),ans.end());
    for(ll i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
