#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<vector<int>> &adj, vector<ll> &leaves, int v=0, int p=-1) {
    if(adj[v].size()==1ULL and p>=0) {
        leaves[v] = 1;
        return;
    }

    for(auto i:adj[v]) {
        if(i==p) continue;
        dfs(adj,leaves,i,v);
        leaves[v]+=leaves[i];
    }
}

void solve() {
    int n,q,x,y;
    cin >> n;

    vector<ll> leaves(n,0);
    vector<vector<int>> adj(n);

    for(int i=1;i<n;i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(adj,leaves);
    
    cin >> q;
    while(q--) {
        cin >> x >> y;
        cout << leaves[x-1]*leaves[y-1] << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
