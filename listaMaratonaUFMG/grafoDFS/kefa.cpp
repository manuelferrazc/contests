#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int dfs(vvi &adj, vi &cats, int v, int p, int m, int g) {
    int ret=0;
    if(g==m and cats[v]) return 0;
    if(adj[v].size()==1ULL and v!=1) return 1;
    
    int c = cats[v]? g+1 : 0;
    for(auto i:adj[v]) {
        if(i==p) continue;
        ret+=dfs(adj,cats,i,v,m,c);
    }

    return ret;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vi cats(n+1);
    for(int i=1;i<=n;i++) {cin >> cats[i];}

    vvi adj(n+1);
    int u,v;
    for(int i=1;i<n;i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << dfs(adj,cats,1,-1,m,0) << '\n';

    return 0;
}
