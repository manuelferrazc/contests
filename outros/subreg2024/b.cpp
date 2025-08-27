#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m,q,tg,a;
    cin >> n >> m;

    vector<vector<int>> v(n);
    vector<vector<int>> v2(m);

    for(int i=0;i<n;i++) {
        int qtd;
        cin >> qtd;
        while(qtd--) {
            int x;
            cin >> x;
            x--;
            v[i].push_back(x);
            v2[x].push_back(i);
        }
    }

    vector<map<int,int>> adj(n);
    for(int i=0;i<m;i++) {
        for(int j=1;j<v2[i].size();j++) {
            int f1 = v2[i][j-1],f2 = v2[i][j];
            adj[f1][f2] = adj[f2][f1] = i;
        }
    }

    cin >> q;

    auto dfs = [&](auto &&self, vector<int> &ans, vector<bool> &vis, int u) -> bool {
        auto it = lower_bound(v[u].begin(),v[u].end(),tg);
        if(it!=v[u].end() and *it==tg) {
            ans.push_back(u);
            return true;
        }

        vis[u] = true;

        for(auto [f,x]:adj[u]) {
            if(vis[f]) continue;
            if(self(self,ans,vis,f)) {
                ans.push_back(u);
                return true;
            }
        }

        return false;
    };

    while(q--) {
        cin >> a >> tg;
        a--;
        tg--;

        vector<int> ans;
        vector<bool> vis(n,false);

        for(int f:v2[a]) {
            if(vis[f]) continue;
            if(dfs(dfs,ans,vis,f)) break;
        }

        if(ans.size()) {
            cout << ans.size()+1 << '\n' << a+1 << ' ';
            reverse(ans.begin(),ans.end());
            for(int i=0;i+1<ans.size();i++) 
                cout << ans[i]+1 << ' ' << adj[ans[i]][ans[i+1]]+1 << ' ';
            cout << ans.back()+1 << ' ' << tg+1 << '\n';
        } else cout << -1 << '\n';
    }

    return 0;
}
