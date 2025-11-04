#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int maxk = 100001;
const int maxn = 100000;

struct Edge {
    int u,v;
    int l,r;

    Edge(int _u, int _v, int _l, int _r): u(_u), v(_v), l(_l), r(_r) {}
};

int p[maxn], h[maxn];

void init() {
    for(int i=0;i<maxn;i++) p[i] = i;
    for(int i=0;i<maxn;i++) h[i] = 1;
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

vector<pair<int,int>> st[4*maxk];

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

void dfs(int pos, int l, int r, int k, int comp) {
    if(k<l) return;
    int rem = op.size();
    for(auto [u,v]:st[pos]) 
        if(unir(u,v)) comp--;

    if(l==r) cout << comp << ' ';
    else {
        int m = (l+r)>>1, ls = 2*pos+1;
        dfs(ls,l,m,k,comp);
        dfs(ls+1,m+1,r,k,comp);
    }

    back(rem);
}

int main() { _
    int n,m,k;
    cin >> n >> m >> k;

    init();

    vector<Edge> v;
    map<pair<int,int>,int> me;

    for(int i=0;i<m;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        if(a>b) swap(a,b);
        me[pair(a,b)] = 0;
    }

    for(int i=1;i<=k;i++) {
        int opt,a,b;
        cin >> opt >> a >> b;
        a--;
        b--;
        if(a>b) swap(a,b);

        if(opt==1) me[pair(a,b)] = i;
        else {
            v.push_back(Edge(a,b,me[pair(a,b)],i-1));
            me.erase(pair(a,b));
        }
    }

    for(auto [e,l]:me) 
        v.push_back(Edge(e.ff,e.ss,l,k));
    me.clear();

    for(auto [u,v,l,r]:v) 
        add(0,0,100000,l,r,pair(u,v));
    v.clear();

    dfs(0,0,100000,k,n);
    cout << '\n';

    return 0;
}
