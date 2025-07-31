#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void dfs1(vector<vector<int>> &adj, vector<int> &p, int v) {
    for(int u:adj[v]) {
        if(u==p[v]) continue;
        p[u] = v;
        dfs1(adj,p,u);
    }
}

int dfs2(vector<vector<int>> &adj, vector<int> &p, vector<bool> &vis, int v) {
    if(vis[v]) return 0;
    int r=1;
    vis[v] = true;
    for(int u:adj[v]) {
        if(u==p[v]) continue;
        r+=dfs2(adj,p,vis,u);
    }
    return r;
}

int main() { _
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> p(n,-1);
    dfs1(adj,p,0);

    vector<int> v(n);
    iota(v.begin(),v.end(),0);

    set<vector<int>> rep;
    double ans = 0;
    do {
        vector<int> v2 = v;
        while(v2.back()) v2.pop_back();
        if(rep.count(v2)) continue;
        vector<bool> vis(n,false);
        double prob=1;
        bool ok = true;
        int qtd=n;
        for(int i:v2) {
            if(vis[i]) {
                ok = false;
                break;
            }
            prob*=1.0/qtd;
            qtd-=dfs2(adj,p,vis,i);
        }
        if(ok) {
            ans+=prob*v2.size();
            rep.insert(v2);
        }
    } while(next_permutation(v.begin(),v.end()));

    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}
