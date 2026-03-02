#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];

int sz[200'000];
int qtd[200'000];
int k;

bool ig[200'000];

ll ans = 0;

void zero() {
    for(int i=0;i<200'000 and qtd[i];i++) qtd[i] = 0;
}

int dfs(int v, int p) {
    sz[v] = 1;
    for(int u:adj[v]) 
    if(u!=p and not ig[u]) sz[v]+=dfs(u,v);
    
    return sz[v];
}

int centroid(int v,int p, int n) {
    for(int u:adj[v])
        if(u!=p and sz[u]>n/2 and not ig[u]) return centroid(u,v,n);
    return v;
}

void dfsAns(int v, int p, int d) {
    int rem = k-d;
    if(rem>=0) ans+=qtd[rem];
    else return;

    for(int u:adj[v]) 
        if(u!=p and not ig[u]) dfsAns(u,v,d+1);
}

void dfsAdd(int v, int p, int d) {
    qtd[d]++;
    for(int u:adj[v]) {
        if(u!=p and not ig[u]) dfsAdd(u,v,d+1);
    }
}

void find(int v) {
    dfs(v,-1);
    v = centroid(v,-1,sz[v]);

    qtd[0]++;
    ig[v] = true;

    for(int u:adj[v]) {
        if(not ig[u]) {
            dfsAns(u,v,1);
            dfsAdd(u,v,1);
        }
    }

    zero();

    for(int u:adj[v]) if(not ig[u]) find(u);
}

int main() { _
    int n,a,b;
    cin >> n >> k;

    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    find(0);

    cout << ans << '\n';

    return 0;
}
