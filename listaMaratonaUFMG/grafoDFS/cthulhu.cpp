#include <bits/stdc++.h>
#include <stdexcept>

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

pair<int,bool> dfs(vvi &adj, vb &v, int u, si &s, int p) {
    v[u] = true;

    for(auto i:adj[u]) {
        if(i==p) continue;
        else if(v[i]) {
            s.insert(u);
            return {i,true};
        }

        auto p = dfs(adj,v,i,s,u);
        if(p.ss) {
            s.insert(u);
            if(p.ff == u) return {0,false};
            else return p;
        }
    }

    return {0,false};
}

void dfss(vvi &adj, vb &v, int u) {
    v[u] = true;
    for(auto i:adj[u]) if(not v[i]) dfss(adj,v,i);
}

bool dfs2(vvi &adj, si &s, vb &v, int u, int p) {
    v[u] = true;

    for(auto i:adj[u]) {
        if(i==p or s.count(i)) continue;
        if(v[i]) return true;

        if(dfs2(adj,s,v,i,u)) return true;
    }

    return false;
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
    int n,m,a,b;
    cin >> n >> m;

    vvi adj(n+10,vi());
    while(m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vb v(n+1,false);
    si s;
    dfs(adj,v,1,s,-1);
    v.assign(n+1,false);
    dfss(adj,v,1);
    for(int i=1;i<=n;i++) if(not v[i]) {
        cout << "NO\n";
        return 0;
    }

    if(s.size()>=3ULL) {
        vb vv(n+1,false);
        bool b = true;
        for(auto f:s) if(dfs2(adj,s,vv,f,-1)) {b = false;break;}            
        if(b==false) {
            cout << "NO\n";
            return 0;
        }

        vvi adj2(n+1,vi());
        for(auto i:s)  for(auto e:adj[i])
            if(s.count(e)) adj2[i].push_back(e);
        if(verifica(adj2,s)) {
            cout << "FHTAGN!\n";
            return 0;
        }
    }
    
    cout << "NO\n";
    
    return 0;
}
