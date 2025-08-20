#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned ull;

struct base {
    vector<ull> s;

    int getdim() {
        return s.size();
    }

    void add(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) {
            auto it = lower_bound(s.begin(), s.end(), mask);
            s.insert(it, mask);
        }
    }

    bool contains(ull mask) {
        for(auto it = s.rbegin();mask and it!=s.rend();it++) {
            mask = min(mask,mask^*it);
        }

        if(mask) return false;
        return true;
    }

    void operator=(base b) {
        s = b.s;
    }

    void join(base &a, base &b) {
        for(auto it = a.s.begin();it!=a.s.end();it++) add(*it);
        for(auto it = b.s.begin();it!=b.s.end();it++) add(*it);
    }

    void join(base &b) {
        for(auto it = b.s.begin();it!=b.s.end();it++) add(*it);
    }

    void print() {
        cout << "BASE: ";
        for(auto i:s) cout << i << ' ';
        cout << '\n';
    }
};

#define MAX 200001
#define MAX2 18

vector<int> adj[MAX];
base ba[MAX][MAX2];
int ka[MAX][MAX2];
int d[MAX], v[MAX];
int l=18;

void dfs(int v, int p=-1) {
    // cout << "vertice: " << v << '\n';
    if(p!=-1) d[v] = d[p]+1;
    ba[v][0].add(::v[v]);
    // ba[v][0].print();
    ka[v][0] = p;

    for(int i=1;i<l;i++) {
        if(ka[v][i-1]!=-1) {
            ka[v][i] = ka[ ka[v][i-1] ][i-1];
            ba[v][i].join(ba[v][i-1],ba[ ka[v][i-1] ][i-1]);
            // cout << i << ' ';ba[v][i].print();
        } else break;
    }

    for(int u:adj[v]) {
        if(u==p) continue;
        dfs(u,v);
    }
}

int getKA(int a, int k) {
    for(int i=0;i<l;i++) if(k&(1<<i)) a = ka[a][i];
    return a;
}

int getLCA(int a, int b) {
    if(d[a]<d[b]) swap(a,b);
    if(d[a]!=d[b]) a = getKA(a,d[a]-d[b]);
    if(a==b) return a;

    for(int i=l-1;i>=0;i--) {
        if(ka[a][i]!=ka[b][i]) {
            a = ka[a][i];
            b = ka[b][i];
        }
    }

    return ka[a][0];
}

void join(int a, int b, int x) {
    base r;
    int lca = getLCA(a,b);
    r.add(v[lca]);

    int k = d[a]-d[lca];

    if(lca!=a) for(int i=0;i<l;i++) if(k&(1<<i)) {
        r.join(ba[a][i]);
        a = ka[a][i];
    }
    a = b;
    k = d[a]-d[lca];

    if(lca!=a) for(int i=0;i<l;i++) if(k&(1<<i)) {
        r.join(ba[a][i]);
        a = ka[a][i];
    }

    if(r.contains(x)) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++) for(int j=0;j<MAX2;j++) ka[i][j] = -1;

    d[0] = -1;
    for(int i=1;i<n;i++) {
        d[i]=-1;
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(0);

    int q;
    cin >> q;

    while(q--) {
        int x,y,k;
        cin >> x >> y >> k;
        join(x-1,y-1,k);
    }

    return 0;
}
