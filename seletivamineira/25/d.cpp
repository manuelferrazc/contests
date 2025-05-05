#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj,ka;
vector<int> d,f;
int l=0, lx=0,n,q;

int dfs(int v, int p=-1) {
    if(p!=-1) d[v] = d[p]+1;
    ka[v][0] = p;

    for(int i=1;i<l;i++) {
        if(ka[v][i-1]!=-1) ka[v][i] = ka[ ka[v][i-1] ][i-1];
    }

    for(int u:adj[v]) {
        if(u==p) continue;
        f[v]+=dfs(u,v);
    }

    return f[v];
}

int getKA(int a, int k) {
    if(d[a]<k) return -1; 
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

int dist(int a, int b) {
    int anc = getLCA(a,b);
    return d[a]+d[b]-2*d[anc];
}

int calc(int x, int y) {
    int di = dist(x,y);
    if(di&1) return 0;

    int anc = getLCA(x,y);

    if(dist(x,anc)==dist(y,anc))
        return f[anc]-f[getKA(x,di/2-1)]-f[getKA(y,di/2-1)]+(n-f[anc]);


    if(d[x]<d[y]) swap(x,y);
    int xxf = getKA(x,di/2-1);
    return f[ka[xxf][0]]-f[xxf];
}

int main() { _
    cin >> n >> q;

    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    adj.resize(n);
    ka.assign(n,vector<int>(l,-1));
    d.resize(n);
    f.assign(n,1);
    
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
        int x,y;
        cin >> x >> y;
        x--;y--;

        cout << calc(x,y) << '\n';
    }

    return 0;
}
