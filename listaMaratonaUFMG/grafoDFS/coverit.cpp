#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

void bfs(vvi &adj, int o, vi &out, int p) {
    vi dist(adj.size(),INT_MAX);
    dist[o] = p;
    queue<int> q;
    q.push(o);

    while(not q.empty()) {
        int v = q.front();
        q.pop();

        for(auto u:adj[v]) {
            if(dist[u]==INT_MAX) {
                dist[u] = dist[v]+1;
                q.push(u);
            }
        }
    }

    for(ull i=1;i<dist.size();i++) if(dist[i]&1) out.push_back(i);
}

void solve() {
    int n,m,a,b;
    cin >> n >> m;

    vvi adj(n+1);
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vi s1,s2;
    bfs(adj,1,s1,0);
    bfs(adj,1,s2,1);

    vi * p;
    if(s1.size()>s2.size())p = &s2;
    else p = &s1;

    cout << p->size() << '\n';
    for(auto it = p->begin();it!=p->end();it++) {
        cout << *it << ' ';
    }
    cout << "\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
