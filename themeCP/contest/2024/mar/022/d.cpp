#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int dfs(map<pair<int,int>,int> &m, vector<vector<int>> &adj, int v, int p=-1) {
    int r=1;
    for(auto i:adj[v]) {
        if(i==p) continue;
        int a = m.at(make_pair(min(p,v),max(p,v)))>m.at(make_pair(min(i,v),max(i,v)));
        r=max(r,dfs(m,adj,i,v)+a);
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    map<pair<int,int>,int> m;
    m.insert(make_pair(make_pair(-1,0),0));
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        m.insert(make_pair(make_pair(min(a,b),max(a,b)),m.size()));
    }

    cout << dfs(m,adj,0) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
