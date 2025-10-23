#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Read {
    queue<int> st;

    Read(string &&s) {
        ifstream f(s);
        int x;
        while(f >> x) st.push(x);
        f.close();
    }
    
    int get() {
        int r = st.front();
        st.pop();
        return r;
    }
};

struct SegTree {
    ll *v;
    
    void reset(int pos = 0, int l = 0, int r = 100010) {
        if(v[pos]==0) return;
        v[pos] = 0;
        int m = (l+r)>>1, ls = 2*pos+1;
        reset(ls,l,m);
        reset(ls+1,m+1,r);
    }
    
    SegTree() {
        v = new ll[400100];
        reset();
    }

    ~SegTree() {
        delete[] v;
    }

    void add(int pos, int l, int r, int i) {
        if(l==r) {
            v[pos]++;
            return;
        }

        int m = (l+r)>>1, ls = 2*pos+1;
        if(i<=m) add(ls,l,m,i);
        else add(ls+1,m+1,r,i);

        v[pos] = v[ls]+v[ls+1];
    }

    ll get(int pos, int l, int r, int lq, int rq) {
        if(rq<l or r<lq) return 0;
        if(lq<=l and r<=rq) return v[pos];

        int m = (l+r)>>1, ls = 2*pos+1;
        
        return get(ls,l,m,lq,rq)+get(ls+1,m+1,r,lq,rq);
    }

    void add(int d) {
        add(0,0,100010,d);
    }

    ll get(int l, int r) {
        return get(0,0,100010,l,r);
    }
};

vector<int> adj[100000];
int parent[100000];
int rem[100000];

int sz[100000];

ll ans,l,r;

SegTree st;

int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for(int u:adj[v]) {
        if(u!=p and not rem[u]) sz[v]+=dfs_sz(u,v);
    }
    return sz[v];
}

int centroid(int v, int p, int n) {
    for(int u:adj[v]) 
        if(u!=p and sz[u]>n/2 and not rem[u]) 
            return centroid(u,v,n);
    
    return v;
}

ll query(ll a, ll b, ll d) {
    return st.get(a,b);
}

void dfs(int v, int p, int dep, bool compute=true) {
    if(compute) {
        if(dep<=r) ans+=query(max(0ll,l-dep),r-dep,dep);
    } else st.add(dep);

    if(dep==r) return;

    for(int u:adj[v])
        if(u!=p and not rem[u])
            dfs(u,v,dep+1,compute);
}

void decomp(int v, int p = -1) {
    int c = centroid(v,v,dfs_sz(v));
    rem[c] = true;
    parent[c] = p;

    st.add(0);
    
    for(int u:adj[c]) {
        if(not rem[u]) {
            dfs(u,c,1);
            dfs(u,c,1,false);
        }
    }

    st.reset();

    for(int u:adj[c])
        if(not rem[u]) decomp(u,c);
}

void solve(Read &re) {
    ll n;
    n = re.get();
    l = re.get();
    r = re.get();

    l = n-1-l;
    r = n-1-r;
    swap(l,r);
    
    ans = 0;

    for(int i=0;i<n;i++) adj[i].clear();
    for(int i=0;i<n;i++) rem[i] = 0;

    for(int i=1;i<n;i++) {
        int a,b;
        a = re.get()-1;
        b = re.get()-1;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    decomp(0);

    cout << ans << '\n';
}

int main() { _
    Read re("awesome.in");
    
    int t = re.get();
    while(t--) solve(re);

    return 0;
}
