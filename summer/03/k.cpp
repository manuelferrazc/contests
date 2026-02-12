#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

#define MAX 300'001

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

struct Bit {
	int n;
	vector<ll> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}
	Bit(vector<int>& v) : n(v.size()), bit(n + 1) {
		for (int i = 1; i <= n; i++) {
			bit[i] += v[i - 1];
			int j = i + (i & -i);
			if (j <= n) bit[j] += bit[i];
		}
	}
	void update(int i, ll x) { // soma x na posicao i
		for (i++; i <= n; i += i & -i) bit[i] += x;
	}
	ll pref(int i) { // soma [0, i]
		ll ret = 0;
		for (i++; i; i -= i & -i) ret += bit[i];
		return ret;
	}
	ll query(int l, int r) {  // soma [l, r]
		return pref(r) - pref(l - 1); 
	}
	int upper_bound(ll x) {
		int p = 0;
		for (int i = __lg(n); i+1; i--) 
			if (p + (1<<i) <= n and bit[p + (1<<i)] <= x)
				x -= bit[p += (1 << i)];
		return p;
	}
};

int get(int *p, int a) {
    return p[a] = (p[a]==a?a:get(p,p[a]));
}

int unir(int *p, int *r, int a, int b) {
    a = get(p,a);
    b = get(p,b);

    if(a==b) return a;

    if(r[b]>r[a]) swap(a,b);
    r[a]+=r[b];
    p[b] = a;

    return a;
}

bool vis[MAX];
int parent[MAX];
int path[MAX];
int in[MAX],out[MAX];
int lx;

void dfs(vector<pair<int,int>> *adj,int v,int acc=0,int p = -1) {
	in[v] = lx++;
    vis[v] = true;
	path[v] = acc;
	parent[v] = p;

    for(auto [u,w]:adj[v]) {
        if(vis[u]==false) dfs(adj,u,acc^w,v);
	}

	out[v] = lx++;
}

int main() { _
    int n, q;
    cin >> n >> q;

    int p[n],r[n];
    for(int i=0;i<n;i++) p[i] = i;
    for(int i=0;i<n;i++) r[i] = 1;

    array<int,4> op[q];
    vector<pair<int,int>> adj[n];
    
    for(int i=0;i<q;i++) {
        cin >> op[i][0] >> op[i][1] >> op[i][2];
        op[i][0]--;
        op[i][1]--;

        int u = op[i][0];
        int v = op[i][1];
        int w = op[i][2];

        if(get(p,u)!=get(p,v)) {
            lca::g[u].push_back(v);
            lca::g[v].push_back(u);
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

            unir(p,r,u,v);
            op[i][3] = 1;
        } else op[i][3] = 2;
    }

    for(int i=0;i<n;i++) vis[i] = false;
    for(int i=0;i<n;i++) {
        if(vis[i]==false) {
            dfs(adj,i);

            lca::g[i].push_back(n);
            lca::g[n].push_back(i);
        }
    }

    lca::build(n+1,n);

	Bit bt(2*n+10);

    for(int i=0;i<q;i++) {
        auto [u,v,x,t] = op[i];
        
        if(t==1) cout << yes;
        else {
            int lc = lca::lca(u,v);
			bool ok = true;

			if((x^path[u]^path[v])!=1) ok = false;

			if(lc==u) {
				if(bt.query(in[lc]+1,in[v])) ok = false;
			} else if(lc==v) {
				if(bt.query(in[lc]+1,in[u])) ok = false;
			} else {
				if(bt.query(in[lc]+1,in[v])) ok = false;
				if(bt.query(in[lc]+1,in[u])) ok = false;
			}

			if(ok==false) {
				cout << no;
				continue;
			}

			cout << yes;

			while(u!=lc) {
				bt.update(in[u],1);
				bt.update(out[u],-1);

				u = parent[u];
			}

			while(v!=lc) {
				bt.update(in[v],1);
				bt.update(out[v],-1);

				v = parent[v];
			}
        }
    }

    return 0;
}
