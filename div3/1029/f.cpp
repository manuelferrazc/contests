#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;

ll fexp(ll n, ll e) {
    if(e==1) return n;
    if(e==0) return 1;

    ll r = fexp(n,e>>1);
    r = r*r%mod;
    if(e&1) r = r*n%mod;

    return r;
}

vector<ll> dist,divs, leaves;
ll l;

void dfs(vector<vector<int>> &adj, int v, int p=-1) {
    if(p==-1) dist[v] = 0;
    else dist[v] = dist[p] + 1;

    int q=0;
    for(int i:adj[v]) {
        if(i==p) continue;
        q++;
        dfs(adj,i,v);
    }

    if(q==0) leaves.push_back(v);
    else if(q==2) divs.push_back(v);
}

void solve() {
    ll n;
    cin >> n;
    
    vector<vector<int>> adj(n);
    for(ll i=1;i<n;i++) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dist.resize(n);
    divs.clear();
    leaves.clear();
    l=0;

    dfs(adj,0,-1);
    if(leaves.size()>2) cout << 0 << '\n';
    else if(leaves.size()==1) cout << fexp(2,n) << '\n';
    else {
        ll v1=1;
        if(dist[leaves[0]]!=dist[leaves[1]]) {
            v1 = fexp(2,max(dist[leaves[0]],dist[leaves[1]])-min(dist[leaves[0]],dist[leaves[1]]))%mod;
            v1 = (v1 + fexp(2,max(dist[leaves[0]],dist[leaves[1]])-min(dist[leaves[0]],dist[leaves[1]])-1))%mod;
        } else v1 = 2;
        cout << v1*fexp(2,dist[divs[0]]+1)%mod << '\n';
    }

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
