#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dfs(vector<vector<int>> &adj, int v) {
    int r=0;
    for(int i:adj[v]) r=max(r,dfs(adj,i));
    return r+1;
}

int main() { _
    int n;
    cin >> n;
    vector<int> c;
    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++) {
        int p;
        cin >> p;
        if(p==-1) c.push_back(i);
        else adj[p-1].push_back(i);
    }

    int ans = 0;
    for(int i:c) ans=max(ans,dfs(adj,i));

    cout << ans << '\n';
    return 0;
}
