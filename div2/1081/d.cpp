#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 200'000;

ll c[MAX];
vector<int> adj[MAX];
ll ans[MAX];

ll sub[MAX];
ll sum[MAX];
ll dep[MAX];

void dfs(int v, int p) {
    ans[v] = 0;
    dep[v] = 0;
    sum[v] = c[v];
    sub[v] = 0;

    ll max1 = 0, max2 = 0;

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);

        sub[v]+=sub[u];
        sum[v]+=sum[u];

        if(max1<=dep[u]) {
            dep[v] = dep[u];
            max2 = max1;
            max1 = dep[u]; 
        } else if(max2<=dep[u]) max2 = dep[u];
    }

    ll act = 0;// resposta sem operacao
    for(int u:adj[v]) if(u!=p) {
        act += sub[u];
    }
    
    ans[v] = act;
    for(int u:adj[v]) if(u!=p) { // resposta fazendo operacao em algum descendente não filho direto
        ans[v] = max(ans[v],act-sub[u]+ans[u]+sum[u]);
    }
    // cout << v+1 << ' ' << act << '\n';
    // resposta fazendo operacao em filho direto
    if((v==0 and adj[0].size()>=2) or (adj[v].size()>=3)) { // garantindo q tenho pelo menos dois filhos
        for(int u:adj[v]) if(u!=p) {
            // cout << v+1 << ' ' << u+1 << ": ";
            if(dep[u]==max1) { // tenta com max2
                // cout << act-sub[u]+(max2+1)*sub[u];
                ans[v] = max(ans[v],act+(max2)*sum[u]);
            } else { // direto com max1
                ans[v] = max(ans[v],act+(max1)*sum[u]);
                // cout << act-sub[u]+(max1+1)*sub[u];
            }
            // cout << '\n';
        }
    }

    dep[v]++;
    sub[v]+=sum[v];
}

void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> i[c];
    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,-1);

    // for(int i=0;i<n;i++) cout << dep[i] << ' ';
    // for(int i=0;i<n;i++) cout << sub[i] << ' ';
    // cout << '\n';
    // cout << '\n';
    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    // cout << '\n';
    // cout << '\n';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
