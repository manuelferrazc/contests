#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct base {
    set<ull> s;

    int getdim() {
        return s.size();
    }

    void add(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) s.insert(mask);
    }

    bool contains(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) return true;
        return false;
    }

    void operator=(base &b) {
        s = b.s;
    }

    base join(base &a, base &b) {
        base r = a;
        for(auto it = b.s.begin();it!=b.s.end();it++) r.add(*it);
        return r;
    }
};

int v[200001];
int depth[200001];

vector<vector<int>> adj;
vector<vector<int>> pr(200001,vector<int>(19,-1));
vector<vector<base>> ba(200001,vector<base>(19));

void dfs(int u, int p=-1) {
    if(p!=-1) {
        pr[u][0] = p;
        ba[u][0].add(v[p]);
        depth[u] = 1+depth[p];
    } else depth[u] = 0;
    ba[u][0].add(v[u]);

    for(int i=1;i<18;i++) {
        if(pr[u][i-1]!=-1) {
            pr[u][i] = pr[p[u][i-1]][i-1];
            ba[u][i] = ba[u][i-1].join(ba[p[u][i-1]][i-1]);
        } else break;
    }

    for(int vv:adj[u]) 
        if(vv!=p) dfs(vv,u);
}

int getk(int u, int k) {
    for(int i=18;i;)
}



int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> v[i];
    adj.resize(n);

    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    return 0;
}
