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

pii bfs(vvi &adj, int v) {
    queue<int> q;
    vi dist(adj.size(),INT_MAX);
    q.push(v);
    dist[v] = dist[0] = 0;

    while(not q.empty()) {
        int x = q.front();
        q.pop();

        for(int e:adj[x]) {
            if(dist[x]+1>=dist[e]) continue;
            dist[e] = 1+dist[x];
            q.push(e);
        }
    }

    int m = 0;
    for(int i=1;i<(int)adj.size();i++) if(dist[i]>dist[m]) m = i;

    return {m,dist[m]};
}

int main() { _
    int n,a,b;
    cin >> n;
    if(n==0) {
        cout << "0\n";
        return 0;
    }

    vvi adj(n+1,vi());
    for(int i=1;i<n;i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pii p = bfs(adj,1);

    cout << bfs(adj,p.ff).ss << '\n';

    return 0;
}
