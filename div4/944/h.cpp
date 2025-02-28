#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
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

int n;

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for(auto u : adj[v]) {
        // cout << u << "\n";
        if(!visited[u]) dfs(u, adj, output);
    }
    
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongy_connected_components(vector<vector<int>> const& adj,
                                  vector<set<int>> &components) {
    int n = adj.size();
    components.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 1; i < n; i++)
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
            components.push_back(si());
            for(int i:component) components.back().insert(i);
            int root = component.front();
            for (auto u : component)
                roots[u] = root;
        }
}

void addAresta(vvi &ar, int col, vvi &mat) {
    int x1 = mat[0][col], x2 = mat[1][col], x3 = mat[2][col];

    ar[x1>0?x1+n:0-x1].pb(x2>0?x2:-x2+n);
    ar[x2>0?x2+n:0-x2].pb(x1>0?x1:-x1+n);

    ar[x1>0?x1+n:0-x1].pb(x3>0?x3:-x3+n);
    ar[x3>0?x3+n:0-x3].pb(x1>0?x1:-x1+n);

    ar[x2>0?x2+n:0-x2].pb(x3>0?x3:-x3+n);
    ar[x3>0?x3+n:0-x3].pb(x2>0?x2:-x2+n);
}

void solve() {
    cin >> n;

    vvi v(3,vi(n));
    for(int i=0;i<3;i++) for(int j=0;j<n;j++) cin >> v[i][j];

    vvi arestas(2*n+1,vi());

    for(int i=0;i<n;i++) addAresta(arestas,i,v);

    vector<si> componentes;
    strongy_connected_components(arestas, componentes);


    for(ull i=0;i<componentes.size();i++) {
        for(auto j:componentes[i]) if(componentes[i].count(j<=n?j+n:j-n)) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}