#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define can first
#define cant second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];
pair<int,int> m[200'000];

void dfs(int v, int p) {
    m[v].cant = 0;
    
    for(int u:adj[v]) {
        if(u!=p) {
            dfs(u,v);
            m[v].cant += m[u].can;
        }
    }

    int best = m[v].cant;
    m[v].can = m[v].cant;

    for(int u:adj[v]) {
        if(u!=p) 
            m[v].can = max(m[v].can,best-m[u].can+m[u].cant+1);
    }
}

int main() { 
    int n,a,b;
    cin >> n;

    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);
    cout << m[0].can << '\n';

    return 0;
}
