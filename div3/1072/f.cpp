#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[200'000];

array<bool,3> dfs(int v, int p) {
    array<bool,3> ret({0,1,0});
    if(v and adj[v].size()==1) return ret;
    
    int qtd = 0;
    int ex1 = 0;
    int ex2 = 0;

    for(auto u:adj[v]) {
        if(u==p) continue;

        array<bool,3> r = dfs(u,v);

        if(r[0]) {
            ex1+=1;
            if(r[2]) ex2+=1;
        } else {
            qtd+=1;
            if(r[2]) ex1+=1;
        }
    }
    ex1 = min(3,ex1);
    ex2 = min(3,ex2);

    for(int i=0;i<=ex1;i++) for(int j=0;j<=ex2;j++) ret[(qtd+i+2*j)%3]=1;

    return ret;
}

void solve() {
    int n;
    cin >> n;

    for(int i=0;i<n;i++) adj[i].clear();

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    if(dfs(0,-1)[0]) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
