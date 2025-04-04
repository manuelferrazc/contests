#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dfs(vector<vector<int>> &adj, int v, int p=-1) {
    int r=1;
    for(auto i:adj[v]) {
        if(i==p) continue;
        r=max(r,dfs(adj,i,v)+1);
    }
    return r;
}

int main() { _
    int n;
    cin >> n;

    vector<bool> m(n,false);
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a==-1) m[i] = true;
        else {
            a--;
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
    }

    int ans=0;
    for(int i=0;i<n;i++) 
        if(m[i]) ans=max(ans,dfs(adj,i));
    
    cout << ans << '\n';

    return 0;
}
