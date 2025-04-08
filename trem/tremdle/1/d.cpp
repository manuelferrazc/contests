#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<set<pair<int,int>>> adjm;
set<int> sss;

bool matching(set<int> &s) {
    s.clear();
    map<int,set<int>> m;
    auto &adj = adjm;
    for(int i=0;i<3*n;i++) m[adj[i].size()].insert(i);
 
    while(m.size() and s.size()<n) {
        auto it = m.begin();
        if(it->ss.empty() or it->ff==0) {
            m.erase(it);
            continue;
        }
 
        int v = *it->ss.begin(),u;
        {u=-1;
            int s=INT_MAX;
            for(auto [e,m]:adj[v]) 
                if(adj[e].size()<s) u=e,s=adj[e].size();
        }
        sss.erase(v);
        sss.erase(u);
        auto edge = adj[v].lower_bound({u,0});
        s.insert(edge->ss);
        for(auto [i,nan]:adj[v]) {
            if(i==u) continue;
            m[adj[i].size()].erase(i);
            if(m[adj[i].size()].empty()) m.erase(adj[i].size());
            adj[i].erase(adj[i].lower_bound({v,-1}));
            m[adj[i].size()].insert(i);
        }
        for(auto [i,nan]:adj[u]) {
            if(i==v) continue;
            m[adj[i].size()].erase(i);
            if(m[adj[i].size()].empty()) m.erase(adj[i].size());
            adj[i].erase(adj[i].lower_bound({u,-1}));
            m[adj[i].size()].insert(i);
        }
        m[adj[v].size()].erase(v);
        if(m[adj[v].size()].empty()) m.erase(adj[v].size());
        m[adj[u].size()].erase(u);
        if(m[adj[u].size()].empty()) m.erase(adj[u].size());
    }
 
    adj.clear();
    return (int)s.size()==n;
}

void solve() {
    cin >> n >> m;
    adjm.resize(3*n,{});
    
    for(int i=0;i<3*n;i++) sss.insert(i);
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adjm[a].insert({b,i+1});
        adjm[b].insert({a,i+1});
    }

    set<int> s;

    if(matching(s)) {
        cout << "Matching\n";
        for(int i:s) cout << i << ' ';
    } else {
        cout << "IndSet\n";
        int qtd=0;
        for(auto it = sss.begin();it!=sss.end() and qtd<n;it++,qtd++) cout << *it+1 << ' ';
    } cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
