#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int q[200000];
vector<int> adj[200000];

int dfs(int v=0, int p=0) {
    q[v] = 0;
    for(int u:adj[v]) {
        if(u==p) continue;
        q[v]+=dfs(u,v);
    }

    return q[v]+1;
}

int main() { _
    int n,a;
    cin >> n;

    for(int i=1;i<n;i++) {
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs();

    for(int i=0;i<n;i++) cout << q[i] << ' ';
    cout << '\n';

    return 0;
}
