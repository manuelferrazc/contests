#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200000];

int ans=0;

int dfs(int v, int p) {
    vector<int> d;
    for(int u:adj[v]) {
        if(u==p) continue;

        d.push_back(dfs(u,v)+1);
    }

    if(d.empty()) return 0;

    sort(d.begin(),d.end());

    ans = max(ans,d.back());
    if(d.size()>1) ans = max(ans, d[d.size()-1]+d[d.size()-2]);

    return d.back();
}

int main() { _
    int n;
    cin >> n;

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);

    cout << ans << '\n';

    return 0;
}
