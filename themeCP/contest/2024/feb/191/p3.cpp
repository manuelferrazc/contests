#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> ans;
vector<int> p;

void dfs(vector<vector<int>> &adj,int v, int a=-1) {
    p.push_back(v);
    if(adj[v].size()==1ULL and a!=-1) {
        ans.push_back(p);
        p.clear();
    }

    for(auto i:adj[v]) {
        if(i==a) continue;
        dfs(adj,i,v);
    }
    
}
void solve() {
    int n;
    cin >> n;
    
    if(n==1) {
        cin >> n;
        cout << "1\n1\n1\n";
        return;
    }

    ans.clear();
    p.clear();

    vector<vector<int>> adj(n+1);
    int r;
    for(int i=1;i<=n;i++) {
        int v;
        cin >> v;
        if(v==i) r=v;
        else {
            adj[v].push_back(i);
            adj[i].push_back(v);
        }
    }

    dfs(adj,r);
    cout << ans.size() << '\n';
    for(auto &i:ans) {
        cout << i.size() << '\n';
        for(auto j:i) cout << j << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) {
        solve();
        if(t) cout << '\n';
    }
    return 0;
}
