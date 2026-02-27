#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 200'000;

struct rmq {
	vector<int> v;
	int n;
	static const int b = 30;
	vector<int> mask, t;
	int op(int x, int y) {
		return v[x]<v[y] ? x : y;
	}
	int msb(int x) {
		return __builtin_clz(1)-__builtin_clz(x);
	}
	rmq() {}
	rmq(const vector<int> &_v): v(_v), n(v.size()), mask(n), t(n) {
		for(int i=0,at=0;i<n;mask[i++] = at|=1) {
			at = (at<<1)&((1<<b)-1);
			while(at and op(i,i-msb(at&-at))==i) at^=at&-at;
		}
		for(int i=0;i<n/b;i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for(int j=1;(1<<j)<=n/b;j++) for(int i=0;i+(1<<j)<=n/b;i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i],t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz = b) {
		return r-msb(mask[r]&((1<<sz)-1));
	}
	int query(int l, int r) {
		if(r-l+1<=b) return small(r,r-l+1);
		int ans = op(small(l+b-1),small(r));
		int x = l/b+1, y = r/b-1;
		if(x<=y) {
			int j = msb(y-x+1);
			ans = op(ans,op(t[n/b*j+x],t[n/b*j+y-(1<<j)+1]));
		}
		return ans;
	}
};

namespace lca {
	vector<int> g[MAX];
	int v[2*MAX], pos[MAX], dep[2*MAX];
	int t;
	rmq RMQ;

	void dfs(int i, int d=0, int p=-1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for(int j:g[i]) if(j!=p) {
			dfs(j,d+1,i);
			v[t] = i;
			dep[t++] = d;
		}
	}
	void build(int n, int root) {
		t=0;
		dfs(root);
		RMQ = rmq(vector<int>(dep,dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a,b),max(a,b))];
	}
}

int pr[200'000];
int v[200'000];

void dfs(int u, int p) {
	pr[u] = p;
	for(auto w:lca::g[u]) {
		if(w!=p) dfs(w,u);
	}
}

int dfs2(int u, int p) {
	for(auto w:lca::g[u]) {
		if(w!=p) v[u]+=dfs2(w,u);
	}
	return v[u];
}

int main() { _
    int n,m,a,b;
    cin >> n >> m;

    for(int i=1;i<n;i++) {
        cin >> a >> b;
        a--;
        b--;

        lca::g[a].push_back(b);
        lca::g[b].push_back(a);
    }

    lca::build(n,0);

	dfs(0,-1);

    while(m--) {
        cin >> a >> b;
        a--;
        b--;

		int lc = lca::lca(a,b);
		if(lc==b) swap(a,b);

		if(lc==a) {
			v[b]++;
			if(pr[a]!=-1) v[pr[a]]--;
		} else {
			v[a]++;
			v[b]++;
			v[lc]--;
			if(pr[lc]!=-1) v[pr[lc]]--;
		}
    }
	dfs2(0,-1);
    for(int i=0;i<n;i++) cout << v[i] <<' ';
    cout << '\n';

    return 0;
}
