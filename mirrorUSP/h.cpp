#include <bits/stdc++.h>
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

struct Aresta {
    ll dest;
    ll abre;
    ll fec;
};

struct ADist {
    ll v;
    ll c;

    bool operator<(const ADist &o) {
        return c<o.c;
    }
};

bool operator<(ADist const & a, const ADist & b) {
    return a.c<b.c;
}

bool operator>(ADist const &a, const ADist &b) {
    return a.c>b.c;
}

ll tempo(ll act, ll ab, ll fe) {
    ll ret = act%(ab+fe);
    if(ret<ab) return 0LL;
    else return (ab+fe)-ret;
}

int main() { _
    ll n,m,t;
    cin >> n >> m >> t;

    vector<vector<Aresta>> v(n+1,vector<Aresta>());
    vll abre(n+1);
    vll fecha(n+1);

    ll u,w,x,y;
    for(ll i=0;i<m;i++) {
        cin >> u >> w >> x >> y;
        v[u].push_back({w,x,y});
        v[w].push_back({u,x,y});
    }

    priority_queue<ADist,vector<ADist>,greater<ADist>> pq;
    pq.push({1,t});

    vb vis(n+1,false);
    vll dist(n+1,LLONG_MAX);
    dist[1] = t;

    while(not pq.empty()) {
        auto e = pq.top();
        pq.pop();

        if(vis[e.v]) continue;
        vis[e.v] = true;

        if(e.v==n) break;

        for(auto p: v[e.v]) {
            if(vis[p.dest]) continue;
            if(dist[e.v]+tempo(e.c,p.abre,p.fec)>=dist[p.dest]) continue;
            dist[p.dest] = dist[e.v]+tempo(e.c,p.abre,p.fec);

            pq.push({p.dest,dist[p.dest]});
        }
    }

    cout << dist[n] << '\n';

    return 0;
}