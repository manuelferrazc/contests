#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;

// Dinitz
//
// O(min(m * max_flow, n^2 m))
// Grafo com capacidades 1: O(min(m sqrt(m), m * n^(2/3)))
// Todo vertice tem grau de entrada ou saida 1: O(m sqrt(n))

struct dinitz {
	const bool scaling = false; // com scaling -> O(nm log(MAXCAP)),
	int lim;                    // com constante alta
	struct edge {
		int to, cap, rev, flow;
		bool res;
		edge(int to_, int cap_, int rev_, bool res_)
			: to(to_), cap(cap_), rev(rev_), flow(0), res(res_) {}
	};

	vector<vector<edge>> g;
	vector<int> lev, beg;
	ll F;
	dinitz(int n) : g(n), F(0) {}

	void add(int a, int b, int c) {
		g[a].emplace_back(b, c, g[b].size(), false);
		g[b].emplace_back(a, 0, g[a].size()-1, true);
	}
	bool bfs(int s, int t) {
		lev = vector<int>(g.size(), -1); lev[s] = 0;
		beg = vector<int>(g.size(), 0);
		queue<int> q; q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (auto& i : g[u]) {
				if (lev[i.to] != -1 or (i.flow == i.cap)) continue;
				if (scaling and i.cap - i.flow < lim) continue;
				lev[i.to] = lev[u] + 1;
				q.push(i.to);
			}
		}
		return lev[t] != -1;
	}
	int dfs(int v, int s, int f = INF) {
		if (!f or v == s) return f;
		for (int& i = beg[v]; i < g[v].size(); i++) {
			auto& e = g[v][i];
			if (lev[e.to] != lev[v] + 1) continue;
			int foi = dfs(e.to, s, min(f, e.cap - e.flow));
			if (!foi) continue;
			e.flow += foi, g[e.to][e.rev].flow -= foi;
			return foi;
		}
		return 0;
	}
	ll max_flow(int s, int t) {
		for (lim = scaling ? (1<<30) : 1; lim; lim /= 2)
			while (bfs(s, t)) while (int ff = dfs(s, t)) F += ff;
		return F;
	}
};

void dfs(int v, int tg, vector<int> *adj, vector<int> &path) {
	path.push_back(v);
	if(v==tg) return;

	int u = adj[v].back();
	adj[v].pop_back();
	dfs(u,tg,adj,path);
}

int main() { _
    int n,m;
	cin >> n >> m;

	dinitz d(n);
	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		d.add(a-1,b-1,1);
	}

	ll qtd = d.max_flow(0,n-1);
	
	vector<int> adj[n];
	for(int i=0;i<n;i++) {
		for(ull j=0;j<d.g[i].size();j++) {
			if(d.g[i][j].res==false and d.g[i][j].flow) adj[i].push_back(d.g[i][j].to);
		}
	}
	
	cout << qtd << '\n';
	while(qtd--) {
		vector<int> p;

		dfs(0,n-1,adj,p);
		cout << p.size() << '\n';
		for(int i:p) cout << i+1 << ' ';
		cout << '\n';
	}

	return 0;
}
