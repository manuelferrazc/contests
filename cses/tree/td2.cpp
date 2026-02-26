#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
vector<int> adj[200'000];

int sub[200'000];
ll dsub[200'000];
ll dnsub[200'000];

int dfs(int v, int p) {
    sub[v]  = 1;
    dsub[v] = 0;

    for(int u:adj[v]) {
        if(u==p) continue;
        sub[v]+=dfs(u,v);
        dsub[v]+=dsub[u];
    }
    
    dsub[v] += sub[v]-1;

    return sub[v];
}

void dfs(int v, int p, ll top) {
    dnsub[v] = top;
    ll c = top + n + dsub[v];

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v, c - dsub[u] - 2*sub[u]);
    }
}

int main() { _
    cin >> n;

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);
    dfs(0,0,0);

    for(int i=0;i<n;i++) cout << dsub[i]+dnsub[i] << ' ';
    cout << '\n';

    return 0;
}
