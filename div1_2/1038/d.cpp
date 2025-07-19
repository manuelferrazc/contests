#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct st {
    ll t;
    ll w;
    ll v;
    ll m;

    st(ll _t, ll _w, ll _v, ll _m): t(_t), w(_w), v(_v), m(_m) {}
};


struct ord {
    bool operator()(const st &a, const st &o) {
        if(a.t<o.t) return true;
        if(a.t>o.t) return false;
        
        return a.w<o.w;
    }
};

void solve() {
    ll n,m;
    cin >> n >> m;

    vector<vector<ll>> adj(n);
    
    for(ll i=0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    priority_queue<st,vector<st>,ord> pq;
    pq.push(st(0,0,0,0));
    vector<vector<ll>> dist(n,vector<ll>(n,LLONG_MAX)), wait(n,vector<ll>(n,LLONG_MAX));
    dist[0][0] = wait[0][0] = 0;

    while(pq.size()) {
        auto [t,w,v,m] = pq.top();
        pq.pop();

        if(dist[v][m]<t or (dist[v][m]==t and wait[v][m]<w)) continue;

        for(ull i=0;i<adj[v].size();i++) {
            ll u = adj[v][(t+i)%adj[v].size()];
            ll nt = t+i+1, nw = w+i;
            ll mod = nt%adj[u].size();
            if(dist[u][mod]>nt or (dist[u][mod]==nt and wait[u][mod]>nw)) {
                dist[u][mod] = nt;
                wait[u][mod] = nw;
                pq.push(st(dist[u][mod],wait[u][mod],u,mod));
            }
        }
    }

    // cout << "costs:\n";
    // for(int i=0;i<n;i++) cout << dist[i] << ' ' << wait[i] << '\n';
    pair<ll,ll> ans = make_pair(LLONG_MAX,LLONG_MAX);

    for(ll i=0;i<n;i++) {
        if(dist.back()[i]<ans.ff) {
            ans.ff = dist.back()[i];
            ans.ss = wait.back()[i];
        } else if(dist.back()[i]==ans.ff and wait.back()[i]<ans.ss) 
            ans.ss = wait.back()[i];
    }

    cout << ans.ff << ' ' << ans.ss << '\n';
    // cout << dist.back() << ' ' << wait.back() << '\n';

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
