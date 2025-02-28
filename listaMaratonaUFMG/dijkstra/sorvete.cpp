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

struct aresta {
    int v;
    int c;
};

int main() { _
    int n,m,a;
    cin >> n >> m >> a;

    vector<vector<aresta>> adj(n+1);

    int x,y,z;
    for(int i=0;i<m;i++) {
        cin >> x >> y >> z;
        adj[x].push_back({y,z});
        adj[y].push_back({x,z});
    }

    si amigos;
    while(a--) {
        cin >> x;
        amigos.insert(x);
    }

    //d1

    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push({0,1});
    vi v(n+1,false), dist(n+1,INT_MAX);
    dist[1] = 0;

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(v[p.s]==true) continue;
        v[p.s] = true;
        for(auto e:adj[p.s]) {
            if(v[e.v]==true or dist[e.v]<=(dist[p.s]+e.c)) continue;
            dist[e.v] = dist[p.s]+e.c;
            pq.push({dist[e.v],e.v});
        }
    }

    
    pq.push({0,n});
    v.clear();
    v.assign(n+1,false);
    vi dist2(n+1,INT_MAX);
    dist2[n] = 0;

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(v[p.s]) continue;
        v[p.s] = true;

        for(auto e:adj[p.s]) {
            if(v[e.v] or dist2[e.v]<=dist2[p.s]+e.c) continue;
            dist2[e.v] = dist2[p.s]+e.c;
            pq.push({dist2[e.v],e.v});
        }
    }


    int o = INT_MAX;
    for(int i:amigos) o = min(o,dist[i]+dist2[i]);

    cout << o << '\n';

    return 0;
}