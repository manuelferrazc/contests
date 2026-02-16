#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
pair<int,int> adj[300'003];
int parent[300'003];

const ll mod = 1'000'000'007;

ll qtd[300'003];
ll ans[300'003];

ll dfs1(int v) {
    if(adj[v].ff) return qtd[v] = 1+dfs1(adj[v].ff)+1+dfs1(adj[v].ss)+1;
    else return qtd[v] = 1;
}

void dfs2(int v) {
    ans[v] = (qtd[v]+ans[parent[v]])%mod;
    if(adj[v].ff) {
        dfs2(adj[v].ff);
        dfs2(adj[v].ss);
    }
}

void solve() {
    cin >> n;

    parent[1] = 0;
    for(int i=1;i<=n;i++) {
        int l,r;
        cin >> l >> r;
        if(l) parent[l] = parent[r] = i;
        adj[i].ff = l;
        adj[i].ss = r;
    }

    dfs1(1);
    qtd[0] = 0;
    dfs2(1);

    // for(int i=0;i<n;i++) cout << qtd[i+1] << ' ' ;
    // cout << '\n';
    for(int i=0;i<n;i++) cout << ans[i+1] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
