#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200000
#define MAX2 18

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
		for (int k=0;k<(int)g[i].size();k++) {
			int j = g[i][k];
			if (j != p) {
				dfs(j, d+1, i);
				v[t] = i, dep[t++] = d;
			}
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

const int UPD = 2e5+10, LOG = 19;
const int MAXS = 4*MAX + UPD*LOG;

namespace perseg {
	int seg[MAXS];
	int rt[UPD], L[MAXS], R[MAXS], cnt, t;
	int n;

	int build(int p, int l, int r) {
		if (l == r) return seg[p] = 0;
		L[p] = cnt++, R[p] = cnt++;
		int m = (l+r)/2;
		return seg[p] = build(L[p], l, m) + build(R[p], m+1, r);
	}
	void build(int n2) {
		n = n2;
		rt[0] = cnt++;
		build(0, 0, n-1);
	}
	int query(int a, int b, int p, int l, int r) {
		if (b < l or r < a) return 0;
		if (a <= l and r <= b) return seg[p];
		int m = (l+r)/2;
		return query(a, b, L[p], l, m) + query(a, b, R[p], m+1, r);
	}
	int query(int a, int b, int tt) {
		return query(a, b, rt[tt], 0, n-1);
	}
	int update(int a, int x, int lp, int p, int l, int r) {
		if (l == r) return seg[p] = seg[lp]+x;
		int m = (l+r)/2;
		if (a <= m)
			return seg[p] = update(a, x, L[lp], L[p]=cnt++, l, m) + seg[R[p]=R[lp]];
		return seg[p] = seg[L[p]=L[lp]] + update(a, x, R[lp], R[p]=cnt++, m+1, r);
	}
	int update(int a, int x, int tt=t) {
		update(a, x, rt[tt], rt[++t]=cnt++, 0, n-1);
		return t;
	}
};

int lx = 0;
void dfs(int v, int p, int *in, int *out) {
	in[v] = lx++;
	for(int i=0;i<lca::g[v].size();i++) {
		int u = lca::g[v][i];
		if(u!=p) dfs(u,v,in,out);
	}

	out[v] = lx++;
}

int main() { _
    int q,n;
	scanf("%d %d", &n, &q);
	
	pair<int,int> w[n];
	for(int i=0;i<n;i++) {
		int x;
		scanf("%d", &x);
		w[i].ff = x;
		w[i].ss = i;
	}
	
	sort(w,w+n);
	
	for(int i=1;i<n;i++) {
		int a,b;
		scanf("%d %d", &a, &b);

		a--;
		b--;
		lca::g[a].push_back(b);
		lca::g[b].push_back(a);
	}
	
	lca::build(n,0);
	// SegTree st(2*n,n);
	perseg::build(2*n);

	int in[n],out[n];

	dfs(0,-1,in,out);

	int time[n];
	for(int i=0;i<n;i++) {
		// st.copy(i);

		int v = w[i].ss;
		time[v] = i+1;

		// st.update(i+1,in[v],1);
		// st.update(i+1,out[v],-1);
		perseg::update(in[v],1);
		perseg::update(out[v],-1);
	}
	
	int u,v,k;
	vector<int> ansv;
	while(q--) {
		scanf(" %d %d %d", &u, &v, &k);
		
		u--;
		v--;

		int lc = lca::lca(u,v);
		int a=1,b=n,ans;
		// cout << u << ' ' << v << ", lca = " << lc  << ":\n";
		// cout << inn[lc] << ' ' << inn [a] << ' ' << inn[b] << '\n';
		while(a<=b) {
			int t = (a+b)/2;
			// if(inn[lc]>inn[a]) cout << "CU\n";
			
			// int qtd = st.get(t,in[lc],in[u])+st.get(t,in[lc],in[v])-(time[lc]<=t);
			int qtd = perseg::query(in[lc],in[u],2*t)+perseg::query(in[lc],in[v],2*t) - (time[lc]<=t);

			// cout << t << ": " << perseg::query(inn[lc],inn[a],2*t+2) << ' ' << perseg::query(inn[lc],inn[b],2*t+2) << ' ' << perseg::query(inn[lc],inn[lc],2*t+2) << '\n';

			if(qtd>=k) {
				ans = w[t-1].ff;
				b=t-1;
			} else a=t+1;
		}

		ansv.push_back(ans);
	}

	for(int i=0;i<(int)ansv.size();i++) printf("%d\n",ansv[i]);
    
    return 0;
}
