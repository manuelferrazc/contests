#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int maxq = 100000;
const int maxn = 100000;

struct Edge {
    int u,v;
    int l,r;

    Edge(int _u, int _v, int _l, int _r): u(_u), v(_v), l(_l), r(_r) {}
};

int p[2*maxn], h[2*maxn];

void init() {
    for(int i=0;i<2*maxn;i++) p[i] = i;
    for(int i=0;i<2*maxn;i++) h[i] = 1;
}

int get(int v) {
    while(v!=p[v]) v = p[v];
    return v;
}

vector<pair<int*, int>> op;

bool unir(int a, int b) {
    a = get(a);
    b = get(b);
    if(a==b) return false;

    if(h[b]>h[a]) swap(a,b);
    
    if(h[a]==h[b]) {
        op.push_back(pair(&h[a],h[a]));
        h[a]++;
    }

    op.push_back(pair(&p[b],p[b]));
    p[b] = a;

    return true;
}

void back(int rem) {
    while(op.size()>rem) {
        auto [a,b] = op.back();
        *a = b;
        op.pop_back();
    }
}

vector<pair<int,int>> st[4*maxq];

void add(int pos, int l, int r, int lq, int rq, pair<int,int> e) {
    if(r<lq or rq<l) return;
    if(lq<=l and r<=rq) {
        st[pos].push_back(e);
        return;
    }

    int m = (l+r)>>1, ls = 2*pos+1;
    add(ls,l,m,lq,rq,e);
    add(ls+1,m+1,r,lq,rq,e);
}

void dfs(int pos, int l, int r, int q, bool bip) {
    if(q<l) return;
    int rem = op.size();
    if(bip) {
        for(auto [u,v]:st[pos]) {
            // cout << ";"
            unir(u,v+maxn);
            unir(v,u+maxn);
            if(get(u)==get(u+maxn) or get(v)==get(v+maxn)) {
                bip = false;
                break;
            }
        } 
    }

    if(l==r) {
        if(bip) cout << "YES\n";
        else cout << "NO\n";
    } else {
        int m = (l+r)>>1, ls = 2*pos+1;
        dfs(ls,l,m,q,bip);
        dfs(ls+1,m+1,r,q,bip);
    }

    back(rem);
}

int main() { _
    int n,q;
    cin >> n >> q;

    init();

    vector<Edge> v;
    map<pair<int,int>,int> me;

    for(int i=0;i<q;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        if(me.count(pair(a,b))) {
            v.push_back(Edge(a,b,me[pair(a,b)],i-1));
            me.erase(pair(a,b));
        } else me[pair(a,b)] = i;
        
    }

    for(auto [e,l]:me) 
        v.push_back(Edge(e.ff,e.ss,l,q-1));
    me.clear();

    for(auto [u,v,l,r]:v) 
        add(0,0,maxq-1,l,r,pair(u,v));
    v.clear();

    dfs(0,0,maxq-1,q-1,true);

    return 0;
}
