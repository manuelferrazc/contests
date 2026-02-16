#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct line {
    ll a,b,c;
    int id;

    line(int x, int y, int z, int i): a(x),b(y),c(z), id(i) {}

    bool intersect(line const &o) {
        if(a==o.a) return b!=o.b or c==o.c;

        ll a1 = a-o.a, b1 = b-o.b, c1 = c-o.c;

        ll d = b1*b1 - 4*a1*c1;
        return d>=0;
    }

    ll val() {
        return a+b+c;
    }
};

int dfs1(vector<int> *adj, int v, int *half) {
    if(half[v]!=-1) return half[v];

    half[v] = 1;
    for(int u:adj[v]) half[v] = max(half[v],dfs1(adj,u,half)+1);
    return half[v];
}

void solve() {
    int n;
    cin >> n;

    vector<line> l;
    vector<line> pos,neg;

    for(int i=0;i<n;i++) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a>0) pos.push_back(line(a,b,c,i));
        else neg.push_back(line(a,b,c,i));
        l.push_back(line(a,b,c,i));
    }

    vector<int> adj[n];

    for(ull i=0;i<pos.size();i++) {
        int id = pos[i].id;
        for(ull j=i+1;j<pos.size();j++) {
            if(pos[i].intersect(pos[j])) continue;
            if(pos[i].val()<pos[j].val()) adj[id].push_back(pos[j].id);
            else adj[pos[j].id].push_back(id);
        }
    }

    for(ull i=0;i<neg.size();i++) {
        int id = neg[i].id;
        for(ull j=i+1;j<neg.size();j++) {
            if(neg[i].intersect(neg[j])) continue;
            if(neg[i].val()>neg[j].val()) adj[id].push_back(neg[j].id);
            else adj[neg[j].id].push_back(id);
        }
    }

    int half[n];
    for(int i=0;i<n;i++) half[i] = -1;
    for(int i=0;i<n;i++) dfs1(adj,i,half);

    // opposite half
    int op_half[n];
    for(ull i=0;i<pos.size();i++) {
        int id = pos[i].id;
        op_half[id] = 0;
        for(ull j=0;j<neg.size();j++) {
            if(pos[i].intersect(neg[j])==false) 
                op_half[id] = max(op_half[id],half[neg[j].id]);
        }
    }

    for(ull i=0;i<neg.size();i++) {
        int id = neg[i].id;
        op_half[id] = 0;
        for(ull j=0;j<pos.size();j++) {
            if(neg[i].intersect(pos[j])==false) 
                op_half[id] = max(op_half[id],half[pos[j].id]);
        }
    }

    for(int i=0;i<n;i++) adj[i].clear();

    for(ull i=0;i<pos.size();i++) {
        int id = pos[i].id;
        for(ull j=i+1;j<pos.size();j++) {
            if(pos[i].intersect(pos[j])) continue;
            if(pos[i].val()>pos[j].val()) adj[id].push_back(pos[j].id);
            else adj[pos[j].id].push_back(id);
        }
    }

    for(ull i=0;i<neg.size();i++) {
        int id = neg[i].id;
        for(ull j=i+1;j<neg.size();j++) {
            if(neg[i].intersect(neg[j])) continue;
            if(neg[i].val()<neg[j].val()) adj[id].push_back(neg[j].id);
            else adj[neg[j].id].push_back(id);
        }
    }

    int g[n];
    queue<int> q;
    for(int i=0;i<n;i++) {
        g[i] = adj[i].size();
        if(g[i]==0) q.push(i);
    }

    // melhor "caminho em subárvore" + half_op de alguem da subarvore
    int best[n];

    while(not q.empty()) {
        int v = q.front();
        q.pop();
        best[v] = op_half[v];

        for(auto u:adj[v]) best[v] = max(best[v],best[u]+1);

        vector<line> *p = &neg;
        if(l[v].a>0) p = &pos;

        for(ull i=0;i<p->size();i++) {
            if(l[v].intersect(p->at(i))==0 and ((l[v].a>0) != (l[v].val()>p->at(i).val()))) {
                g[p->at(i).id]--;
                if(g[p->at(i).id]==0) q.push(p->at(i).id);
            }
        }
    }

    for(int i=0;i<n;i++) cout << half[i]+best[i] << ' ';

    cout << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
