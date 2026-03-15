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


bool dfsCheck(vector<pair<int,bool>> *adj, vector<bool> &vis, int v, int p) {
    vis[v] = true;
    for(auto [u,dir]:adj[v]) {
        if(u==p) continue;

        if(vis[u] or dfsCheck(adj,vis,u,v)) return true;
    }
    return false;
}

int get(int *p, int a) {
    return p[a] = (p[a]==a ? a : get(p,p[a]));
}

void unir(int *p, int *s, int a, int b) {
    a = get(p,a);
    b = get(p,b);

    if(a==b) return;
    if(s[b]>s[a]) swap(a,b);
    s[a]+=s[b];
    p[b] = a;
}

bool dfs2(vector<pair<int,bool>> *adj, string &vis, int v) {
    vis[v] = '1';
    for(auto [u,ok]:adj[v]) {
        if(ok and (vis[u]=='1' or dfs2(adj,vis,u))) return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    
    int q[n];
    vector<int> can[n];

    for(int i=0;i<n;i++) {
        q[i] = 0;
        for(int j=0;j<n;j++) if(v[i][j]=='1') {
            q[i]++;
            can[i].push_back(j);
        }
    }

    for(int i=0;i<n;i++) {
        if(v[i][i]=='0') return no();

        for(int j=0;j<n;j++) {
            if(i==j) continue;
            if(v[i][j]=='1' and v[j][i]=='1') return no();
        }
    }

    vector<pair<int,bool>> adj[n];
    
    int qtd=0;

    for(int i=0;i<n;i++) {
        vector<pair<int,int>> s;
        for(int j=0;j<n;j++) {
            if(i!=j and v[i][j]=='1') s.push_back(pair(q[j],j));
        }
        
        sort(s.rbegin(),s.rend());
        
        int p[n],r[n];
        for(int j=0;j<n;j++) p[j] = j;
        for(int j=0;j<n;j++) r[j] = 1;

        for(auto [lx,u]:s) {

            bool nw = true;
            for(ull j=0;j<can[u].size();j++) {
                if(r[get(p,can[u][j])]>1) {
                    nw = false;
                    break;
                }
                unir(p,r,can[u][0],can[u][j]);
            }
            unir(p,r,can[u][0],i);
            if(nw) {
                adj[i].push_back(pair(u,true));
                adj[u].push_back(pair(i,false));
                qtd++;
            }
        }

        for(auto u:can[i]) unir(p,r,i,u);
        if(r[get(p,i)]!=can[i].size()) return no();
    }
    
    
    vector<bool> vis(n,false);

    if(dfsCheck(adj,vis,0,-1) or qtd!=n-1) return no();
    for(int i=0;i<n;i++) if(vis[i]==false) return no();
    for(int i=0;i<n;i++) {
        string vis2(n,'0');
        if(dfs2(adj,vis2,i) or vis2!=v[i]) return no();
    }

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
