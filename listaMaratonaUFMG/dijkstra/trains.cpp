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

struct edge {
    ll v;
    ll time;
    ll depart;
};

ll time(ll k, ll t) {
    ll ret = t%k;
    if(ret==0LL) return ret;
    else return k-ret;
}

int main() { _
    ll n,m,s,f;
    cin >> n >> m >> s >> f;

    ll a,b,c,d;
    vector<vector<edge>> adj(n+1);
    while(m--) {
        cin >> a >> b >> c >> d;
        adj[a].push_back({b,c,d});
        adj[b].push_back({a,c,d});
    }


    vll dist(n+1,LLONG_MAX);
    vb v(n+1,false);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    pq.push({0,s});
    dist[s] = 0;

    while(not pq.empty()) {
        auto p = pq.top();
        pq.pop();

        if(v[p.s]) continue;
        v[p.s] = true;

        for(auto e:adj[p.s]) {
            if(v[e.v]) continue;
            ll t = time(e.depart, dist[p.s])+e.time;
            if(dist[e.v]<=dist[p.s]+t) continue;
            dist[e.v] = dist[p.s]+t;
            pq.push({dist[e.v],e.v});
        }
    }

    if(dist[f]==LLONG_MAX) cout << "-1\n";
    else cout << dist[f] << '\n';
    return 0;
}