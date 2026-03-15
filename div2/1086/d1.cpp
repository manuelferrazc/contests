#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
    cout << "NO\n";
}

bool dfs(vector<pair<int,bool>> *adj, vector<bool> &vis, int v, int p) {
    vis[v] = true;
    for(auto [u,lx]:adj[v]) {
        if(u==p) continue;

        if(vis[u] or dfs(adj,vis,u,v)) return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    
    int q[n];
    for(int i=0;i<n;i++) {
        q[i] = 0;
        for(int j=0;j<n;j++) if(v[i][j]=='1') q[i]++;
    }

    for(int i=0;i<n;i++) {
        if(v[i][i]=='0') return no();

        string aux = v[i];
        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(v[i][j]=='1' and v[j][i]=='1') return no(); // matei c2

            if(v[i][j]=='1') {
                for(int k=0;k<n;k++) if(v[j][k]=='1') aux[k] = '1';
            }
        }

        if(aux!=v[i]) return no(); // matei ck, k>=3, e outros erros
    }


    vector<pair<int,bool>> adj[n];
    int qtd=0;

    for(int i=0;i<n;i++) {
        vector<pair<int,int>> s;
        for(int j=0;j<n;j++) {
            if(i!=j and v[i][j]=='1') s.push_back(pair(q[j],j));
        }

        sort(s.rbegin(),s.rend());

        vector<bool> seen(n,false);
        for(auto [lx,u]:s) {
            bool nw = false, rep = false;

            for(int j=0;j<n;j++) {
                if(v[u][j]=='0') continue;

                if(seen[j]) rep = true;
                else {
                    nw = true;
                    seen[j] = true;
                }
            }

            if(nw and rep) return no();
            else if(nw) { // todos são novos, tem aresta
                qtd++;
                adj[i].push_back(pair(u,true));
                adj[u].push_back(pair(i,false));
            }
        }
    }

    if(qtd!=n-1) return no();

    vector<bool> vis(n,false);
    if(dfs(adj,vis,0,-1)) return no();
    for(int i=0;i<n;i++) if(vis[i]==false) return no(); 

    cout << "YES\n";
    for(int i=0;i<n;i++) {
        for(auto [a,b]:adj[i]) {
            if(b) cout << i+1 << ' ' << a+1 << '\n';
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
