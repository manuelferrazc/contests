#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int v) {
    return p[v] = (p[v]==v?v:get(p,p[v]));
}

void unionn(vector<int> &p, vector<vector<int>> &g, int u, int v) {
    u = get(p,u);
    v = get(p,v);
    if(u==v) return;
    if(g[u].size()<g[v].size()) swap(u,v);
    for(int leite:g[v]) g[u].push_back(leite);
    g[v].clear();
    p[v] = u;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vector<int> p(n);
    vector<vector<int>> g(n,vector<int>(1));
    for(int i=0;i<n;i++) {
        p[i] = i;
        g[i][0] = i;
    }

    while(m--) {
        int k;
        cin >> k;
        vector<int> aux(k);
        for(int &semnome:aux) cin >> semnome;
        for(int i=1;i<k;i++) unionn(p,g,aux[i-1]-1,aux[i]-1);
    }

    vector<int> ans(n,0);
    for(int i=0;i<n;i++) {
        if(get(p,i)!=i) continue;
        for(int v:g[i]) ans[v] = g[i].size();
    }
    for(int i:ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
