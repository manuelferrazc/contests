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

int calc(int a, int b, int f) {
    int ab = getLCA(a,b), fa = getLCA(a,f), fb = getLCA(b,f);
    int com = getLCA(ab,f);

    if(f==a or f==b) return 1;
    if(a==b) return d[a]-2*d[com]+d[f]+1;
    
    if(com==f) return d[ab]-d[f]+1;
    if(com==a) {
        if(fb==f) return 1;
        if(fb==b) return d[f]-d[b]+1;
        return d[f]+1-d[fb];
    }
    if(com==b) {
        if(fa==f) return 1;
        if(fa==a) return d[f]-d[a]+1;
        return d[f]+1-d[fa];
    }

    if(com==fa and fa==fb and fb==ab) return d[f]-d[com]+1;
    if(fa==f or fb==f) return 1;
    if(fa==a) return d[f]-d[a]+1;
    if(fb==b) return d[f]-d[b]+1;
    if(ab!=com) return d[ab]-2*d[com]+d[f]+1;
    if(d[fa]>d[fb]) return d[f]-d[fa]+1;
    return d[f]-d[fb]+1;
}

int main() { _
    int n,q;
    cin >> n >> q;

    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    adj.resize(n);
    ka.assign(n,vector<int>(l,-1));
    d.resize(n);
    d[0] = 0;

    for(int i=1;i<n;i++) {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }

    dfs(0);

    while(q--) {
        int a,b,c;
        cin >> a >> b >> c;

        a--;
        b--;
        c--;

        int ans = max({calc(a,b,c),calc(a,c,b),calc(b,c,a)});
        cout << ans << '\n';
    }

    return 0;
}
