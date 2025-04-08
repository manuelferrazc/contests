#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<set<pair<int,int>>> adjm;
vector<set<int>> adj;

bool ind_set(set<int> &s) {
    s.clear();
    map<int,set<int>> m;
    for(int i=0;i<3*n;i++) m[adj[i].size()].insert(i);

    while(m.size() and s.size()<n) {
        auto it = m.begin();
        if(it->ss.empty()) {
            m.erase(it);
            continue;
        }
        int v = *it->ss.begin();
        s.insert(v);
        for(int e:adj[v]) {
            for(int sla:adj[e]) {
                if(sla==v or adj[v].count(sla)) continue;
                m[adj[sla].size()].erase(sla);
                if(m[adj[sla].size()].empty()) m.erase(adj[sla].size());
                adj[sla].erase(e);
                m[adj[sla].size()].insert(sla);
            }
        }
        for(int e:adj[v]) {
            m[adj[e].size()].erase(e);
            if(m[adj[e].size()].empty()) m.erase(adj[e].size());
        }
        it->ss.erase(v);
        if(it->ss.empty()) m.erase(it);
    }
    adj.clear();
    return (int)s.size()==n;
}

bool matching(set<int> &s) {
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
    adj.resize(3*n,{});
    adjm.resize(3*n,{});
    
    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].insert(b);
        adj[b].insert(a);
        adjm[a].insert({b,i+1});
        adjm[b].insert({a,i+1});
    }

    set<int> s;

    if(matching(s)) {
        cout << "Matching\n";
        for(int i:s) cout << i << ' ';
    } else if(ind_set(s)) {
        cout << "IndSet\n";
        for(int i:s) cout << i+1 << ' ';
    } else cout << "Impossible";
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
