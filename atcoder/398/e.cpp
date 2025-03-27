#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int q = 0;

void dfs1(vector<set<int>> &v, vector<int> &dist,int r, int x,int p=-1) {
    if(dist[x]>1 and (dist[x]&1) and x>r) q++;

    for(auto i:v[x]) {
        if(i==p) continue;
        dist[i] = dist[x]+1;
        dfs1(v,dist,r,i,x);
    }
}

int dfs2(vector<set<int>> &v, vector<set<int>> &extra, vector<int> &dist,int r, int x,int p=-1) {
    if(dist[x]>1 and (dist[x]&1) and extra[x].count(r)==0ULL) return x;

    for(auto i:v[x]) {
        if(i==p) continue;
        dist[i] = dist[x]+1;
        int ababa = dfs2(v,extra,dist,r,i,x);
        if(ababa!=-1) return ababa;
    }
    return -1;
}

pair<int,int> find(vector<set<int>> &adj, vector<set<int>> &extra, int n) {
    for(int i=1;i<=n;i++) {
        vector<int> dist(n+1,0);
        int o = dfs2(adj,extra,dist,i,i);
        if(o!=-1) return make_pair(i,o);
    }
    exit(0);
}

void solve() {
    int n;
    cin >> n;
    vector<set<int>> adj(n+1),sla(n+1);

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    for(int i=1;i<=n;i++) {
        vector<int> dist(n+1,0);
        dfs1(adj,dist,i,i);
    }

    if(q&1) {
        cout << "First\n";
        auto i = find(adj,sla,n);
        cout << i.ff << ' ' << i.ss << '\n';
        sla[i.ff].insert(i.ss);
        sla[i.ss].insert(i.ff);
    } else cout << "Second\n";

    while(true) {
        int a,b;
        cin >> a >> b;
        if(a==-1) return;
        sla[a].insert(b);
        sla[b].insert(a);

        auto i = find(adj,sla,n);
        cout << i.ff << ' ' << i.ss << '\n';
        sla[i.ff].insert(i.ss);
        sla[i.ss].insert(i.ff);
    }
}

int main() {
    int t=1;
    while(t--) solve();
    return 0;
}
