#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Line { // f(x) = ax+b
    ll a, b;

    Line(ll _a=0, ll _b=LLONG_MAX) {
        a=_a;
        b=_b;
    }

    ll val(ll x) {
        return a*x+b;
    }
};

struct Node {
    int l=-1, r=-1;
    Line ln;

    Node() {}

    Node(int _l, int _r): l(_l), r(_r) {}

    Node(int _l, int _r, Line _ln): l(_l), r(_r), ln(_ln) {}

    ll val(ll x) {
        return ln.val(x);
    }
};

struct LiChao { // LiChao Tree de máximo, se não tem segmento returna LLONG_MIN
    vector<Node> v;
    ll l_lim, r_lim;
    int aux;

    LiChao(ll _l, ll _r) {
        l_lim = _l;
        r_lim = _r;
        v.push_back(Node());
    }

    int createNode() {
        v.push_back(Node());
        return v.size()-1;
    }

    void addNewLine(Line ln, int pos, ll l, ll r) {
        if(v[pos].val(l)>ln.val(l)) swap(v[pos].ln,ln);
        if(v[pos].val(r)<=ln.val(r)) return;
        
        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        if(v[pos].val(m)<=ln.val(m)) {
            if(v[pos].r==-1) {
                aux = createNode();
                v[pos].r = aux;
            }
            addNewLine(ln,v[pos].r,m+1,r);
        } else {
            swap(v[pos].ln,ln);
            if(v[pos].l==-1) {
                aux = createNode();
                v[pos].l = aux;
            }
            addNewLine(ln,v[pos].l,l,m);
        }
    }

    void addLine(Line ln, int pos, ll l, ll r, ll lq, ll rq) {
        if(r<lq or rq<l) return;
        if(lq<=l and r<=rq) return addNewLine(ln,pos,l,r);

        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;
        
        if(v[pos].l==-1) {
            aux = createNode();
            v[pos].l = aux;
        }
        
        if(v[pos].r==-1) {
            aux = createNode();
            v[pos].r = aux;
        }

        addLine(ln,v[pos].l,l,m,lq,rq);
        addLine(ln,v[pos].r,m+1,r,lq,rq);
    }

    ll query(int pos, ll l, ll r, ll x) {
        if(l==r) return v[pos].val(x);

        ll m = (l+r)/2;
        if(l+r<0 and ((l+r)&1)) m--;

        ll ret = LLONG_MAX;
        if(x<=m) {
            if(v[pos].l!=-1) ret = query(v[pos].l,l,m,x);
            return min(ret,v[pos].val(x));
        } else {
            if(v[pos].r!=-1) ret = query(v[pos].r,m+1,r,x);
            return min(ret,v[pos].val(x));
        }
    }

    ll query(ll x) {
        return query(0,l_lim,r_lim,x);
    }

    void addLine(Line ln, ll l, ll r) {
        addLine(ln,0,l_lim,r_lim,l,r);
    }

    void addLine(Line ln) {
        addLine(ln,0,l_lim,r_lim,l_lim,r_lim);
    }
};

int a[100000];
int b[100000];
ll ans[100000];
vector<int> adj[100000];
LiChao lc(-100000,100000);

struct aux {
    LiChao lc;
    vector<Line> v;

    int size() {
        return v.size();
    }

    void combine(aux *p) {
        for(Line &l:p->v) {
            lc.addLine(l);
            v.push_back(l);
        }
        delete p;
    }

    aux(): lc(-100000,100000) {}
    ~aux() {}
};

aux* dfs(int v, int p=0) {
    if(adj[v].size()==1ull and v!=p) {
        ans[v] = 0;
        aux *x = new aux;

        x->v.push_back(Line(b[v],0));
        x->lc.addLine(x->v.back());

        return x;
    }

    if(adj[v].front()==p) swap(adj[v].front(),adj[v].back());
    aux *x = dfs(adj[v][0],v);
    for(int i=1;i<(int)adj[v].size();i++) {
        if(adj[v][i]==p) continue;

        aux * p2 = dfs(adj[v][i],v);
        if(x->size()<p2->size()) swap(x,p2);
        x->combine(p2);
    }

    ans[v] = x->lc.query(a[v]);
    x->v.push_back(Line(b[v],ans[v]));
    x->lc.addLine(x->v.back());
    return x;
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    for(int i=1;i<n;i++) {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto p = dfs(0);
    delete p;

    for(int i=0;i<n;i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
