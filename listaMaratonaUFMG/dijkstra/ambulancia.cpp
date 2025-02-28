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

si h;

int dijkstra(vector<vector<pii>> &adj, int o) {
    vi dist(adj.size(),INT_MAX);
    dist[o] = 0;
    vi v(dist.size(),false);
    priority_queue<pii,vector<pii>, greater<pii>> pq;
    pq.push({0,o});

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(h.count(p.s)) return p.f;

        if(v[p.s]) continue;
        v[p.s] = true;

        for(auto e : adj[p.s]) {
            if(v[e.f] or dist[e.f]<=dist[p.s]+e.s) continue;
            dist[e.f] = dist[p.s]+e.s;
            pq.push({dist[e.f],e.f});
        }
    }

    return INT_MAX;
}

void solve(int n, int m, int q) {
    vector<vector<pii>> adj(n+1);
    h.clear();
    int a,b,c;
    while(m--) {
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    b = q;
    while(q--) {
        cin >> a;
        h.insert(a);
    }
    if(b==n) {
        cout << "0\n";
        return;
    }

    int max = INT_MIN;

    for(int i=1;i<=n;i++) {
        if(not h.count(i)) {
            max = ::max(max,dijkstra(adj, i));
        }
    }

    cout << max << '\n';
}

int main() { _
    int n,m,q;

    while(cin >> n >> m >> q) solve(n,m,q);

    return 0;
}