#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
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

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongy_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    vector<int> roots(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            sort(component.begin(), component.end());
            components.push_back(component);
            int root = component.front();
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

int conta(vector<vector<int>> &comp, int v, vector<int> &out, string &s) {
    int c=0;
    for(auto i:comp[v]) if(s[i]=='0') c++;
    for(auto i:comp[v]) out[i] = c;
    return c;
}

int dfs(vector<vector<int>> &comp,vector<int> &out, vector<vector<int>> &adj, string &s, int v) {
    if(adj[v].size()==0ULL) return conta(comp,v,out,s);

    int c=0;
    for(auto i:adj[v]) {
        c+=dfs(comp,out,adj,second,i);
    }

    for(auto i:comp[v]) c+=(s[i]=='0');
    for(auto i:comp[v]) out[i] = c;
    return c;
}

void solve() {
    int n;
    cin >> n;
    vi v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<int>> adj(n+1);
    for(int i=1;i<=n;i++) adj[i].push_back(v[i]);
    vector<vector<int>> comp, ad;
    strongy_connected_components(adj, comp, ad);

    string s;
    cin >> s;
    s = " " + s;
    vi dp(n+1,0);

    for(int i=0;i<comp.size();i++) {
        dfs(comp,dp,ad,s,i);
    }
    for(int i=1;i<=n;i++) cout << dp[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}