#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool bfs(vector<int> *adj, int v, int *color) {
    color[v] = 1;
    queue<int> q;
    q.push(v);

    while(not q.empty()) {
        int u = q.front();
        q.pop();
        
        for(auto u2:adj[u]) {
            if(color[u2]==0) {
                color[u2] = 3-color[u];
                q.push(u2);
            } else if(color[u]==color[u2]) {
                return false;
            }
        }
    }

    exit(0);

    return true;
}

int main() { _
    int n,m;
    cin >> n >> m;

    vector<pair<int,int>> e(m);
    for(int i=0;i<m;i++) {
        cin >> e[i].ff >> e[i].ss;
        e[i].ff--;
        e[i].ss--;
    }


    vector<int> ans;
    int color[n];

    for(int i=0;i<m;i++) {
        vector<int> adj[n];

        for(int j=0;j<m;j++) {
            if(j==i) continue;

            int a = e[j].ff;
            int b = e[j].ss;

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        // for(int i=0;i<n;i++) {
        //     cout << i << ": ";
        //     for(int u:adj[i]) cout << u << ' ';
        //     cout << '\n';
        // }

        fill(color,color+n,0);

        bool ok = true;
        for(int i=0;i<n;i++) {
            if(color[i]==0 and bfs(adj,i,color)==false) {
                ok = false;
                break;
            } 
        }
        // for(int i=0;i<n;i++) cout << color[i] << ' ';
        // cout << '\n';

        if(ok) ans.push_back(i+1);
    }

    cout << ans.size() << '\n';
    for(int i:ans) cout << i << ' ';
    if(ans.size()) cout << '\n';

    return 0;
}
