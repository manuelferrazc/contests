#include <bits/stdc++.h>
#include <queue>
#include <vector>

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

void solve(int n, int m, int c, int k) {
    vector<vector<pii>> adj(n);

    int u,v,w;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vi dc(c);
    dc[c-1] = 0;
    for(int u=c-2;u>=0;u--) {
        for(auto p:adj[u]) {
            if(p.f==u+1) {
                dc[u] = dc[u+1]+p.s;
                break;
            }
        }
    }

    vi dist(n,INT_MAX);
    dist[k] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,k});
    vb vi(n,false);

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(vi[p.s]) continue;
        vi[p.s] = true;

        if(p.s<c) continue;

        for(auto e:adj[p.s]) {
            if(vi[e.f] or dist[e.f]<=dist[p.s]+e.s) continue;
            dist[e.f] = dist[p.s]+e.s;
            pq.push({dist[e.f],e.f});
        }
    }

    int ans = INT_MAX;
    for(int i=0;i<c;i++) if(dist[i]!=INT_MAX) ans = min(ans,dist[i]+dc[i]);

    cout << ans << '\n';
}

int main() { _
    int n,m,c,k;
    cin >> n >> m >> c >> k;

    while(n) {
        solve(n,m,c,k);
        cin >> n >> m >> c >> k;
    }

    return 0;
}