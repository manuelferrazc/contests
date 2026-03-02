#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> adj[10'000];

int in[10'000];
int out[10'000];
int lx = 0;

vector<int> ans;
vector<array<int,3>> cont;
vector<array<int,3>> ncont;
vector<array<int,3>> t;

int color[10'000];
int st[10'000];

void dfs(int v, int p) {
    st[v] = 1;
    in[v] = lx++;

    for(auto [u,id]:adj[v]) {
        if(u==p) continue;

        if(color[u]==0) {
            color[u] = 3 - color[v];
            t.push_back({v,u,id});
            dfs(u,v);
        } else if(st[u]==2) continue;
        else if(color[u]==color[v]) cont.push_back({u,v,id});
        else ncont.push_back({u,v,id});
    }

    out[v] = lx++;
    st[v] = 2;
}


int main() { _
    int n,m;
    cin >> n >> m;

    for(int i=1;i<=m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        
        adj[a].push_back(pair(b,i));
        adj[b].push_back(pair(a,i));
    }

    for(int i=0;i<n;i++) {
        if(color[i]==0) {
            color[i] = 1;
            dfs(i,-1);
        }
    }

    if(cont.size()==1) ans.push_back(cont[0][2]);
    else if(cont.empty()) {
        for(auto [fds,pqp,id]:ncont) ans.push_back(id);
    }


    for(auto [v,u,id]:t) { // v tá em cima
        bool ok = true;

        for(auto [v1,u1,cu]:cont) { // v1 tá em cima
            // toda v1u1 tem q ser v1 ancestral de v, e u ancestral de de u1
            if(in[v]<in[v1] or out[v1]<out[v] or in[u1]<in[u] or out[u]<out[u1]) {
                ok = false;
                break;
            }
        }

        if(cont.size()) for(auto [v1,u1,cu]:ncont) { // v1 tá em cima
            // erro se ter algum v1u1 que v1 é ancestral de v E u é ancestral de u1 (ou igual em ambos os casos)
            if(in[v]>=in[v1] and out[v1]>=out[v] and in[u1]>=in[u] and out[u]>=out[u1]) {
                ok = false;
                break;
            }
        }

        if(ok) ans.push_back(id);
    }

    sort(ans.begin(),ans.end());
    ans.erase(
        unique(ans.begin(),ans.end()),
        ans.end()
    );

    cout << ans.size() << '\n';
    for(int i:ans) cout << i << ' ';
    if(ans.size()) cout << '\n';

    return 0;
}
