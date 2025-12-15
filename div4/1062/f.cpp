#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;
ll ans;

vector<int> adj[200'000];
int tam[200'000];

int dfs1(int v, int p=-1) {
    tam[v] = 1;

    for(int u:adj[v]) 
        if(u!=p) tam[v]+=dfs1(u,v);

    return tam[v];
}

void dfs2(int v, int p=-1) {
    vector<int> aux;
    aux.push_back(n-tam[v]);
    
    for(int u:adj[v]) 
        if(u!=p) dfs2(u,v);

    for(int u:adj[v]) 
        if(u!=p) aux.push_back(tam[u]);

    for(int x:aux) if(n-x>=k) ans+=x;
}

void solve() {
    cin >> n >> k;

    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs1(0);

    ans = n;
    dfs2(0);

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
