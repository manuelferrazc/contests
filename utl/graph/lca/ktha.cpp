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

void dfsr(int v, int p) {
    if(d[v]==-1) return;
    for(int i:adj[v]) {
        if(i==p) continue;
        dfsr(i,v);
    }
    d[v] = -1;
}

void solve() { 
    int n,q;
    cin >> n;
    
    l=0;
    for(int i=0;i<30;i++) if(n&(1<<i)) l=i+1;
    adj.assign(200000,vector<int>());
    ka.assign(200000,vector<int>(l,-1));
    d.assign(200000,-1);

    int r;
    for(int i=0;i<n;i++) {
        int a,b;
        cin >> a >> b;
        if(b==0) r=a-1;
        else {
            a--;
            b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    
    d[r] = 0;
    dfs(r);
    cin >> q;

    int a,b,op;
    while(q--) {
        cin >> op >> a;
        a--;

        if(op==0) {
            cin >> b;
            if(d[a]==-1) continue;
            b--;
            d[b] = d[a]+1;
            ka[b].assign(l,-1);
            ka[b][0] = a;

            for(int i=1;i<l;i++) {
                if(ka[b][i-1]!=-1) ka[b][i] = ka[ ka[b][i-1] ][i-1];
            }
        }
        else if(op==1) d[a] = -1;
        else {
            cin >> b;
            if(d[a]<b) cout << /* a << ' ' << b << ' ' << d[a] << ' ' */ 0 << '\n';
            else cout << getKA(a,b)+1 << '\n';
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
