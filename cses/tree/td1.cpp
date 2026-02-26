#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];
int l[200'000];
int d[200'000];

int dfs(int v, int p) {
    l[v] = 0;

    for(int u:adj[v]) {
        if(u!=p) l[v] = max(l[v],dfs(u,v)+1);
    }

    return l[v];
}

void sfd(int v, int p, int dd) {
    int m1=0,m2=0;

    for(int u:adj[v]) {
        if(u==p) continue;

        if(l[u]+1>=m1) {
            m2 = m1;
            m1 = l[u]+1;
        } else if(l[u]>m2) m2 = l[u]+1;
    }

    d[v] = max(m1,dd);

    for(int u:adj[v]) {
        if(u!=p) {
            if(l[u]+1==m1) sfd(u,v,max(dd+1,m2+1));
            else sfd(u,v,max(dd+1,m1+1));
        }
    }
}

int main() { _
    int n;
    cin >> n;

    for(int i=1,a,b;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0);
    sfd(0,0,0);

    for(int i=0;i<n;i++) cout << d[i] << ' ';
    cout << '\n';

    return 0;
}
