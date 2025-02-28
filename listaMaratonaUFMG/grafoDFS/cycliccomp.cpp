#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

void dfs(vvi &adj, vb &v, int u,si &s) {
    s.insert(u);
    v[u] = true;

    for(auto i:adj[u]) if(not v[i]) dfs(adj,v,i,s);
}

bool verifica(vvi &adj, si &s) {
    for(auto i: s) if(adj[i].size()!=2ULL) return false;

    int x = *s.begin();
    int i = adj[x][0];
    si usados;
    usados.insert(i);
    for(;i!=x;) {
        usados.insert(i);
        if(usados.count(adj[i][0])==0) i = adj[i][0];
        else if(usados.count(adj[i][1])==0) i = adj[i][1];
        else return false;
    }

    return true;
}

int main() { _
    int a,b,n, m, ans = 0;
    cin >> n >> m;

    vb v(n+1,false);
    vvi adj(n+1);

    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    si s;
    for(int i=1;i<=n;i++) {
        if(v[i]) continue;

        s.clear();
        dfs(adj,v,i,s);

        if(s.size()>2ULL) {
            if(verifica(adj,s)) ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
