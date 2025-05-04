#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<vector<int>> adj,ka,oc;
vector<int> d,tin,tout;
int l=0,lx=0;

void dfs(int v, int p=-1) {
    if(p!=-1) d[v] = d[p]+1;
    ka[v][0] = p;
    tin[v] = lx++;

    oc[d[v]].push_back(tin[v]);
    for(int i=1;i<l;i++) {
        if(ka[v][i-1]!=-1) ka[v][i] = ka[ ka[v][i-1] ][i-1];
    }

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);
    }

    tout[v] = lx++;
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

int calc(int v, int p) {
    if(d[v]<p) return 0;

    int dist = d[v];
    v = getKA(v,p);
    auto ite = upper_bound(oc[dist].begin(),oc[dist].end(),tout[v]);
    auto it = lower_bound(oc[dist].begin(),oc[dist].end(),tin[v]);
    return ite-it-1;
}

int main() { _
    int n,q;
    cin >> n;

    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    adj.resize(n);
    tin.resize(n);
    tout.resize(n);
    oc.resize(n+1);
    ka.assign(n,vector<int>(l,-1));
    d.resize(n);
    
    vector<int> r;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        a--;
        if(a==-1) r.push_back(i);
        else {
            adj[a].push_back(i);
            adj[i].push_back(a);
        }
    }
    
    for(int sla:r) {
        d[sla] = 0;
        dfs(sla);
    }
    cin >> q;

    while(q--) {
        int v,p;
        cin >> v >> p;
        v--;

        cout << calc(v,p) << ' ';
    }
    cout << '\n';

    return 0;
}
