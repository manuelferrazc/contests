#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

double dfs(vector<vector<int>> &adj, int v, int p=-1, int r=1) {
    double ret=1.0/r;
    for(int u:adj[v]) {
        if(u==p) continue;
        ret+=dfs(adj,u,v,r+1);
    }
    return ret;
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

    cout << fixed << setprecision(10) << dfs(adj,0) << '\n';

    return 0;
}