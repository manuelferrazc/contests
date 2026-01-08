#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int>* ar;

int qtd[200'000];
set<int> sla[200'000];
int mx;
int mx2;

void dfs(int v, int p, int d, ar adj) {
    mx = max(mx,d);
    qtd[d]++;
    mx2 = max(mx2,qtd[d]);
    sla[d].insert(p);

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v,d+1,adj);
    }
}

void solve() {
    int n;
    cin >> n;
    for(int i=0;i<n;i++) {
        qtd[i] = 0;
        sla[i].clear();
    }

    mx = 0;
    mx2 = 0;
    vector<int> adj[n];

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0,0,adj);

    bool ex = 0;
    for(int i=1;i<=mx;i++) {
        if(qtd[i]==mx2 and sla[i].size()==1) ex = true;
    }

    if(ex) cout << mx2+1 << '\n';
    else cout << mx2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
