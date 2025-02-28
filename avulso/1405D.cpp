#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,a,b,da,db;

void dfs(vector<vector<int>> &adj,vector<int> &dist, int v) {
    for(auto i:adj[v]) {
        if(dist[i]==INT_MAX) {
            dist[i] = dist[v]+1;
            dfs(adj,dist,i);
        }
    }
}

pair<int,int> dfs2(vector<vector<int>> &adj, vector<int> &dist, int v) {
    pair<int,int> ret(v,dist[v]);

    for(auto i:adj[v]){
        if(dist[i]==INT_MAX) {
            dist[i] = dist[v]+1;
            auto p = dfs2(adj,dist,i);
            if(p.ss>ret.ss) {
                ret.ss = p.ss;
                if(ret.ss-dist[v]<=da) ret.ff = v;
                else ret.ff = p.ff;
            }
        }
    }

    return ret;
}

void solve() {
    cin >> n >> a >> b >> da >> db;
    a--;
    b--;
    vector<vector<int>> adj(n);
    for(int i=1;i<n;i++) {
        int aa,bb;
        cin >> aa >>bb;
        aa--;
        bb--;
        adj[aa].push_back(bb);
        adj[bb].push_back(aa);
    }
    
    vector<int> dist(n,INT_MAX);
    dist[a]=0;
    dfs(adj,dist,a);
    
    if(2*da>=db or dist[b]<=da) {
        cout << "Alice\n";
        return;
    }

    dist.assign(n,INT_MAX);
    pair<int,int> p;
    for(int i=0;;i++) {
        if(adj[i].size()==1ULL) {
            dist[i] = 0;
            p = dfs2(adj,dist,i);
            break;
        }
    }

    dist.assign(n,INT_MAX);
    dist[p.ff] = 0;
    dfs(adj,dist,p.ff);
    for(auto i:dist) {
        if(i>da) {
            cout << "Bob\n";
            return;
        }
    }

    cout << "Alice\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
