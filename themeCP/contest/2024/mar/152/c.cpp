#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n,m;
    cin >> n >> m;

    vector<vector<int>> adj(n+1);
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int leaves=0;
    for(int i=1;i<=n;i++) if(adj[i].size()==1ULL) leaves++;
    
    cout << (n-1-leaves) << ' ' << leaves/(n-1-leaves) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
