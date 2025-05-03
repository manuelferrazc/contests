#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj,ka;
vector<int> d;
int l=0;

void dfs(int v, int p=-1) {
    if(p!=-1) d[v] = d[p]+1;
    ka[v][0] = p;

    for(int i=1;i<l;i++) {
        if(ka[v][i-1]!=-1) ka[v][i] = ka[ ka[v][i-1] ][i-1];
    }

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);
    }
}

int getKA(int a, int k) {
    for(int i=0;i<l;i++) if(k&(1<<i)) a = ka[a][i];
    return a;
}

int getLCA(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    if(d[a]!=d[b]) a = getKA(a,d[a]-d[b]);
    if(a==b) return a;
    
    for(int i=l-1;i>=0;i--) {
        if(ka[a][i]!=ka[b][i]) {
            a = ka[a][i];
            b = ka[b][i];
        }
    }

    return ka[a][0];
}


int main() { _
    int n,q;
    cin >> n >> q;
    
    l=0;
    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    adj.assign(n,vector<int>());
    ka.assign(n,vector<int>(l,-1));
    d.assign(n,-1);

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    dfs(0);

    while(q--) {
        int k;
        cin >> k;

        vector<int> v(k);
        for(int &i:v) {
            cin >> i;
            i--;
        }

        int m = v[0];
        for(int i=1;i<k;i++) {
            if(d[v[i]]>d[m]) m = v[i];
        }

        bool ok=true;
        for(int i=0;i<k;i++) {
            int lca = getLCA(m,v[i]);

            if(lca!=v[i]) {
                lca = getLCA(m,ka[v[i]][0]);
                if(lca!=ka[v[i]][0]) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
