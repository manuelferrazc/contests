#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int adj[100'000];
int deg[100'000];

int to[100'000];
int vis[100'000];

map<int,vector<int>> m;

int dfs(int v) {
    if(vis[v]) {
        m.insert(pair(v,vector<int>()));
        to[v] = v;
        vis[v] = 2;
        return v;
    }

    vis[v] = 1;

    int x;
    if(vis[adj[v]]==2) x = to[adj[v]];
    else x = dfs(adj[v]);

    if(x==v) m.insert(pair(x,vector<int>()));

    to[v] = x;
    if(deg[v]==0) m[x].push_back(v);

    vis[v] = 2;
    return x;
}


int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        int f;
        cin >> f;

        adj[i] = f-1;
        deg[f-1]++;
    }

    for(int i=0;i<n;i++) if(vis[i]==false) dfs(i);

    // for(int i=0;i<n;i++) cout << to[i]+1 << '\n';

    vector<pair<int,int>> ans;

    if(m.size()==1) {
        auto [c,l] = *m.begin();

        for(auto lv:l) ans.push_back(pair(c,lv));
    } else {
        for(auto it = m.begin();it!=m.end();it++) {
            auto [c,l] = *it;
            
            auto it2 = next(it);
            if(it2==m.end()) it2 = m.begin();

            if(it2->ss.size()==0) ans.push_back(pair(c,it2->ff));
            else ans.push_back(pair(c,it2->ss[0]));

            for(int i=1;i<it->ss.size();i++) {
                ans.push_back(pair(c,it->ss[i]));
            }
        }


    }

    cout << ans.size() << '\n';

    for(auto [a,b]:ans) cout << a+1 << ' ' << b+1 << '\n';

    return 0;
}
