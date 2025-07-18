#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll ans=0;

void dfs(vector<vector<pair<ll,ll>>> &adj, vector<map<ll,ll>> &qtd, vector<ll> &a, vector<pair<ll,ll>> &p, ll v, ll par=-1) {
    for(auto [u,w]:adj[v]) {
        if(u==par) continue;
        p[u] = make_pair(v,w);
        qtd[v][a[u]]+=w;
        dfs(adj,qtd,a,p,u,v);
    }

    for(auto [cor,x]:qtd[v]) if(a[v]!=cor) ans+=x;
}

void solve() {
    //cout << "Teste\n";
    ll n,q;

    cin >> n >> q;
    vector<ll> a(n);
    vector<pair<ll,ll>> p(n,make_pair(-1,-1));
    for(ll &i:a) cin >> i;

    vector<vector<pair<ll,ll>>> adj(n);
    vector<map<ll,ll>> v(n);

    for(ll i=0;i<n-1;i++) {
        ll u,v,c;
        cin >> u >> v >> c;
        u--;
        v--;
        adj[u].push_back(make_pair(v,c));
        adj[v].push_back(make_pair(u,c));
    }

    ans=0;
    dfs(adj,v,a,p,0);

    while(q--) {
        ll u,c;
        cin >> u >> c;
        u--;

        if(c!=a[u]) {
            ans-=v[u][c];
            ans+=v[u][a[u]];
            
            auto [parent,cost] = p[u];
            if(parent!=-1) {
                v[parent][a[u]]-=cost;
                v[parent][c]+=cost;
                if(c==a[parent]) ans-=cost;
                else if(a[u]==a[parent]) ans+=cost;
            }

            a[u] = c;
        }

        cout << ans << '\n';
    }

}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
