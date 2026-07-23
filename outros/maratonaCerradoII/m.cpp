#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'000

vector<int> g[MAX];
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX];

template<typename T> struct rmq {
	vector<T> v;
	int n;
	static const int b = 30;
	vector<int> mask, t;
	int op(int x, int y) {return v[x]<v[y]?x:y;}
	int msb(int x) { return __builtin_clz(1) - __builtin_clz(x);}
	rmq() {}
	rmq(const vector<T> & v_): v(v_), n(v.size()), mask(n), t(n) {
		for(int i=0,at=0;i<n;mask[i++]=at |=1) {
			at = (at<<1)&((1<<b)-1);
			while(at and op(i,i-msb(at&-at))==1) at^=at&-at;
		}
		for(int i=0;i<n/b;i++) t[i] = b*i+b-1-msb(mask[b*i+b-1]);
		for(int j=1;(1<<j)<=n/b;j++) for(int i=0;i+(1<<j)<=n/b;i++)
			t[n/b*j+i] = op(t[n/b*(j-1)+i], t[n/b*(j-1)+i+(1<<(j-1))]);
	}
	int small(int r, int sz=b) {return r-msb(mask[r]&((1<<sz)-1));}
	T query(int l, int r) {
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
	int v[2*MAX], pos[MAX], dep[2*MAX];
	int t;
	rmq<int> RMQ;

	void dfs(int i, int d=0, int p=-1) {
		v[t] = i, pos[i] = t, dep[t++] = d;
		for(int j:g[i]) if(j!=p) {
			dfs(j,d+1,i);
			v[t] = i, dep[t++]=d;
		}
	}
	void build(int n, int root) {
		t=0;dfs(root);
		RMQ = rmq<int>(vector<int>(dep,dep+2*n-1));
	}
	int lca(int a, int b) {
		a = pos[a], b = pos[b];
		return v[RMQ.query(min(a,b),max(a,b))];
	}
	int dist(int a, int b) {
		return dep[pos[a]] + dep[pos[b]] - 2*dep[pos[lca(a,b)]];
	}
};

int dfs(int i, int &t, int p = -1) {
	int lo = id[i] = t++;
	s.push(i);
	vis[i] = 2;

	for(int j:g[i]) {
		if(j==p) continue;
		if(not vis[j]) lo = min(lo,dfs(j,t,i));
		else if(vis[j]==2) lo = min(lo,id[j]);
	}

	if(lo== id[i]) while(true) {
		int u = s.top();s.pop();
		vis[u] = 1, comp[u] = i;
		if(u==i) break;
	}

	return lo;
}

void tarjan(int n) {
	int t = 0;
	fill(vis,vis+n,0);
	for(int i=0;i<n;i++) if(not vis[i]) dfs(i,t);
}

int metro[MAX];

int mdfs(int v, int p = -1) {
	int idd = INT_MIN;
	for(int u:g[v]) {
		if(u!=p) idd = max(idd,mdfs(u,v));
	}

	metro[v] = max(metro[v],idd);
	return idd;
}

int main() { _
	int n;
	cin >> n;
	fill(metro,metro+n,-1);

	for(int i=1;i<n;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	mdfs(0);

	for(int i=0;i<n;i++) if(metro[i]!=i) g[i].push_back(metro[i]);

	//tarjan(n);
	lca::build(n,0);

	vector<int> adj[n];
	int root = metro[0];

	map<int,int> pai;
	stack<int> s;
	stack<int> fim;
	s.push(0);
	vector<bool> raizc(n,false);
	
	while(s.size()) {
		int pqp = s.top();
		s.pop();
		raizc[pqp] = true;

		for(auto u:adj[pqp]) {
			if(metro[u]!=metro[pqp]) s.push(u);
			
		}
		if(metro[metro[pqp]]!=-1) pai[metro[metro[pqp]]] = metro[pqp];
	}

	for(int i=0;i<n;i++) if(

	int q;
	cin >> q;

	return 0;
}
