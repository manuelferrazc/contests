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

    operator bool() {
        return st.size()>0ULL;
    }
};

vector<int> adj[100000];
int parent[100000];
int rem[100000];

int sz[100000];

int altura_max;

int qtd[100000];

ll ans,l,r;

int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for(int u:adj[v]) {
        if(u!=p and not rem[u]) sz[v]+=dfs_sz(u,v);
    }
    return sz[v];
}

int centroid(int v, int p, int n) {
    for(int u:adj[v]) 
        if(v!=p and sz[u]>n/2 and not rem[u]) 
            return centroid(u,v,n);
    
    return v;
}

ll query(int a, int b);

void dfs(int v, int p=-1, int dep) {
    altura_max = max(altura_max,dep);
    ans-=query(n-2-r-dep,n-2-l-d2);

    qtd[dep]++;
    for(int u:adj[v])
        if(u!=p and not rem[u])
            dfs(u,v,dep+1);
}

void decomp(int v, int p = -1) {
    int c = centroid(v,v,dfs_sz(v));
    rem[c] = true;
    parent[c] = p;
    
    for(int u:adj[v])
        if(not rem[u]) dfs(u,c,1);
    ans-=query(n-2-r,n-2-l);
    
    

    for(int u:adj[v])
        if(not rem[u]) decomp(u,c);
}


void solve(Read &re) {
    ll n;
    n = re.get();
    l = re.get();
    r = re.get();

    ans = (n-1)*(n*(n-1))/2;

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
