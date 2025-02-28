#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
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
typedef map<int,int> mii;
typedef set<int> si;

void dijkstra(vector<vector<pii>> &adj, vi &dist, int o) {
    dist[o] = 0;
    vb v(127,false);
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,o});

    while(not pq.empty()) {
        auto p=pq.top();
        pq.pop();

        if(v[p.ss]) continue;
        v[p.ss] = true;

        for(auto e:adj[p.ss]) {
            if(v[e.f] or dist[e.f]<=dist[p.ss]+e.ss) continue;
            dist[e.f] = dist[p.ss]+e.ss;
            pq.push({dist[e.f],e.f});
        }
    }
}

int main() { _
    string s,t;
    cin >> s >> t;
    
    vector<vector<pii>> adj(127);

    int m,w;
    char a,b;
    cin >> m;

    while(m--) {
        cin >> a >> b >> w;
        adj[a].push_back({b,w});
    }

    vvi dist(127,vi(127,INT_MAX));

    for(int i=33;i<127;i++) dijkstra(adj, dist[i], i);

    int ans = 0;
    for(ull i=0;i<s.size();i++) {
        if(dist[s[i]][t[i]]==INT_MAX) {
            cout << "-1\n";
            return 0;
        }
        ans+=dist[s[i]][t[i]];
    }

    cout << ans << '\n';
    
    return 0;
}