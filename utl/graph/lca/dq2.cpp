#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<pair<int,int>>> adj;
vector<vector<vector<int>>> ka;
vector<int> d;
int l=0;

void dfs(int v, int p=-1) {
    if(p!=-1) d[v] = d[p]+1;
    
    for(int i=1;i<l;i++) {
        if(ka[v][i-1][0]!=-1) {
            ka[v][i][0] = ka[ ka[v][i-1][0] ][i-1][0];
            ka[v][i][1] = min(ka[v][i-1][1],ka[ ka[v][i-1][0] ][i-1][1]);
            ka[v][i][2] = max(ka[v][i-1][2],ka[ ka[v][i-1][0] ][i-1][2]);
        }
    }

    for(auto [u,c]:adj[v]) {
        if(u==p) continue;
        ka[u][0][0] = v;
        ka[u][0][1] = ka[u][0][2] = c;
        dfs(u,v);
    }
}

int getKA(int a, int k) {
    for(int i=0;i<l;i++) if(k&(1<<i)) a = ka[a][i][0];
    return a;
}

int getLCA(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    if(d[a]!=d[b]) a = getKA(a,d[a]-d[b]);
    if(a==b) return a;
    
    for(int i=l-1;i>=0;i--) {
        if(ka[a][i][0]!=ka[b][i][0]) {
            a = ka[a][i][0];
            b = ka[b][i][0];
        }
    }

    return ka[a][0][0];
}

pair<int,int> get(int a, int k) {
    if(k==0) return make_pair(INT_MAX,INT_MIN);

    pair<int,int> p = {ka[a][0][1],ka[a][0][2]};
    for(int i=0;i<l;i++) if(k&(1<<i)) {
        p.ff = min(p.ff,ka[a][i][1]);
        p.ss = max(p.ss,ka[a][i][2]);
        a = ka[a][i][0];
    }
    return p;
}

int main() { _
    int n, q;
    cin >> n;

    adj.resize(n);
    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    ka.assign(n,vector<vector<int>>(l,{-1,INT_MAX,-1}));

    for(int nettinho = 1;nettinho<n;nettinho++) {
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    d.resize(n);
    d[0] = 0;
    dfs(0);

    cin >> q;

    while(q--) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        int anc = getLCA(a,b);

        pair<int,int> p1 = get(a,d[a]-d[anc]), p2 = get(b,d[b]-d[anc]);

        cout << min(p1.ff,p2.ff) << ' ' << max(p1.ss,p2.ss) << '\n';
    }

    return 0;
}
