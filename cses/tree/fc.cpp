#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];
int sz[200'000];
int n;

int dfs(int v, int p) {
    sz[v] = 1;
    for(int u:adj[v]) 
        if(u!=p) sz[v]+=dfs(u,v);
    
    return sz[v];
}

int centroid(int v,int p) {
    for(int u:adj[v]) 
        if(u!=p and sz[u]>n/2) return centroid(u,v);
    
    return v;
}

int main() { _
    int a,b;
    cin >> n;

    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;
        
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,-1);

    cout << centroid(0,-1)+1 << '\n';

    return 0;
}
