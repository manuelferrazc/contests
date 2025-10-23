#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 100000

template<typename T> struct rmq {
	vector<T> v;
	int n; static const int b = 30;
	vector<int> mask, t;

	int op(int x, int y) { return v[x] < v[y] ? x : y; }
	int msb(int x) { return __builtin_clz(1)-__builtin_clz(x); }
	rmq() {}
	rmq(const vector<T>& v_) : v(v_), n(v.size()), mask(n), t(n) {
		for (int i = 0, at = 0; i < n; mask[i++] = at |= 1) {
			at = (at<<1)&((1<<b)-1);
			while (at and op(i, i-msb(at&-at)) == i) at ^= at&-at;
		}
		for (int i = 0; i < n/b; i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for (int j = 1; (1<<j) <= n/b; j++) for (int i = 0; i+(1<<j) <= n/b; i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz = b) { return r-msb(mask[r]&((1<<sz)-1)); }
	T query(int l, int r) {
		if (r-l+1 <= b) return small(r, r-l+1);
		int ans = op(small(l+b-1), small(r));
		int x = l/b+1, y = r/b-1;
		if (x <= y) {
			int j = msb(y-x+1);
			ans = op(ans, op(t[n/b*j+x], t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

namespace lca {
	vector<int> g[MAX];
	int v[2*MAX], pos[MAX], dep[2*MAX];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d = 0, int p = -1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for (int j : g[i]) if (j != p) {
			dfs(j, d+1, i);
			v[t] = i, dep[t++] = d;
		}
	}
	void build(int n, int root) {
		t = 0;
		dfs(root);
		RMQ = rmq<int>(vector<int>(dep, dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a, b), max(a, b))];
	}
	int dist(int a, int b) {
		return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a, b)]];
	}
}

ll d[MAX];
vector<pair<int,ll>> adj[MAX];

void dfsd(int v, int p=-1) {
    for(auto [u,w]:adj[v]) {
        if(u!=p) {
            d[u] = d[v]+w;
            dfsd(u,v);
        }
    }
}

ll dist(int u, int v) {
    auto lc = lca::lca(u,v);
    return d[u]+d[v]-2*d[lc];
}

vector<ll> count1[MAX];
map<int,vector<ll>> count2[MAX];
int parent[MAX];
int rem[MAX];
int sz[MAX];
int origem[MAX];


int dfs_sz(int v, int p = -1) {
    sz[v] = 1;
    for(auto [u,w]:adj[v]) {
        if(u!=p and not rem[u]) sz[v]+=dfs_sz(u,v);
    }
    return sz[v];
}

int centroid(int v, int p, int n) {
    for(auto [u,w]:adj[v]) 
        if(u!=p and sz[u]>n/2 and not rem[u]) 
            return centroid(u,v,n);
    
    return v;
}

void dfs(int v, int p, int c, ll w, vector<ll> &vec) {
    count1[c].push_back(w);
    vec.push_back(w);

    for(auto [u,w2]:adj[v])
        if(u!=p and not rem[u])
            dfs(u,v,c,w+w2,vec);
}

void decomp(int v, int v2=-1, int p = -1) {
    int c = centroid(v,v,dfs_sz(v));
    rem[c] = true;
    
    parent[c] = p;
    origem[c] = v2;
    
    count1[c].push_back(0);
    for(auto [u,w]:adj[c]) {
        if(not rem[u]) {
            dfs(u,c,c,w,count2[c][u]);
            sort(count2[c][u].begin(),count2[c][u].end());
        }
    }

    sort(count1[c].begin(),count1[c].end());

    for(auto [u,w]:adj[c])
        if(not rem[u]) decomp(u,u,c);
}

int main() { _
    int n,q;
    cin >> n >> q;
    
    for(int i=0;i<n;i++) rem[i] = 0;
    
    for(int i=1;i<n;i++) {
        int a,b;
        ll w;
        cin >> a >> b >> w;
        a--;
        b--; 
    
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});

        lca::g[a].push_back(b);
        lca::g[b].push_back(a);
    }

    lca::build(n,0);
    d[0] = 0;
    dfsd(0);
    
    decomp(0);

    while(q--) {
        int v;
        ll l;
        cin >> v >> l;
        v--;

        ll ans = upper_bound(count1[v].begin(),count1[v].end(),l)-count1[v].begin();
        int act = parent[v];
        ll orig = origem[v];
        while(act!=-1) {
            ll l2 = l-dist(v,act);

            ans+=upper_bound(count1[act].begin(),count1[act].end(),l2)-count1[act].begin();
            ans-=upper_bound(count2[act][orig].begin(),count2[act][orig].end(),l2)-count2[act][orig].begin();
            
            orig = origem[act];
            act = parent[act];
        }

        cout << ans << '\n';
    }
    
    return 0;
}
