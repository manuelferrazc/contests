#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 50'000

int in[MAX],out[MAX];
bool dist[MAX];
short c[MAX];
vector<int> adj[MAX];
pair<int,int> sb[MAX];

int lx=0;

pair<int,int> dfs(int v, int p,bool ev) {
    in[v] = lx++;
    dist[v] = ev;

    sb[v] = pair(c[v],0);
    for(auto u:adj[v]) {
        if(p==u) continue;
        auto [a,b] = dfs(u,v,not ev);

        sb[v].ff^=b;
        sb[v].ss^=a;
    }

    out[v] = lx++;

    return sb[v];
}

int main() { _
    int n;
    int a,b;
    cin >> n;

    for(int i=0;i<n;i++) cin >> c[i];
    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0,0,0);

    int q;
    cin >> q;

    while(q--) {
        cin >> a >> b;
        a--;
        b--;

        if(in[a]<in[b] and out[b]<out[a]) cout << "INVALID\n";
        else {
            int x = sb[0].ss;

            if(dist[a]==0) x^=sb[a].ss;
            else x^=sb[a].ff;

            if(dist[b]==0) x^=sb[a].ff;
            else x^=sb[a].ss;

            if(x) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
