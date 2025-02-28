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

int dfs1(vvi &adj, int u, int p) {
    if(adj[u].size()>2ULL) return 0;

    for(auto i:adj[u]) {
        if(i==p) continue;
        return 1+dfs1(adj,i,u);
    }

    return 0;
}

int dfs2(vvi &adj, int u,int p) {
    if(adj[u].size()==3ULL or adj[u].size()==4ULL) return 0;

    int r=0;
    for(auto i:adj[u]) {
        if(i==p) continue;
        r+=dfs2(adj,i,u);
    }

    return r+1;
}

int main() { _
    int n,m;
    cin >> n >> m;
    int ans = n;

    vvi adj(n+1);
    int a,b;
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++) {
        if(adj[i].size()==1ULL) {
            ans-=dfs1(adj,i,-1);
        } else if(adj[i].size()>=5ULL) a = i;
    }

    ans-=dfs2(adj,a,-1);

    cout << ans << '\n';

    return 0;
}
