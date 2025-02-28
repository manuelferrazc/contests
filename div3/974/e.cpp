#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

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


void dijkstra(vector<vector<pair<ll,ll>>> const &adj, vll &dist, const vb &cav, ll o) {
    dist.assign(adj.size(), LLONG_MAX);
    dist[o] = 0;
    
    vll dc(adj.size(),LLONG_MAX);
    vi vis(adj.size(), 0);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0,o});

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq2;

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if(cav[p.s]) {
            pq2.push(p);
            dc[p.s] = dist[p.s];
            continue;
        }

        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e:adj[p.s]) {
            if((dist[p.s]+e.s)<dist[e.f]) {
                dist[e.f] = dist[p.s]+e.s;
                pq.push({dist[e.f],e.f});
            }
        }
    }

    for(ull i=0;i<vis.size();i++) vis[i] = false;

    while(not pq2.empty()) {
        auto p = pq2.top();
        pq2.pop();

        if(vis[p.s]) continue;
        vis[p.s] = true;

        for(auto e:adj[p.s]) {
            if(p.f+(e.s>>1)<dc[e.f]) {
                dc[e.f] = p.f+(e.s>>1);
                pq2.push({dc[e.f],e.f});
            }
        }
    }

    for(ull i=1;i<adj.size();i++) dist[i] = min(dist[i],dc[i]);
}

void solve() {
    ll n,m,h;
    cin >> n >> m >> h;

    vector<vector<pair<ll,ll>>> adj(n+1);

    vb cav(n+1,false);
    while(h--) {
        int a;
        cin >> a;
        cav[a] = true;
    }

    while(m--) {
        ll a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    ll ans = LLONG_MAX;
    vll d1,dn;
    dijkstra(adj,d1,cav,1LL);
    dijkstra(adj,dn,cav,n);

    for(ll i=1;i<=n;i++) ans = min(ans,max(d1[i],dn[i]));
    
    if(ans==LLONG_MAX) cout << "-1\n";
    else cout << ans << '\n';
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}