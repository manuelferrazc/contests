#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 100'000

int n;
vector<int> g[MAX];
vector<int> gi[MAX]; // grafo invertido
int vis[MAX];
stack<int> S;
int comp[MAX]; // componente conexo de cada vertice

void dfs(int k) {
	vis[k] = 1;
	for (int i = 0; i < (int) g[k].size(); i++)
		if (!vis[g[k][i]]) dfs(g[k][i]);

	S.push(k);
}

void scc(int k, int c) {
	vis[k] = 1;
	comp[k] = c;
	for (int i = 0; i < (int) gi[k].size(); i++)
		if (!vis[gi[k][i]]) scc(gi[k][i], c);
}

void kosaraju() {
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) if (!vis[i]) dfs(i);

	for (int i = 0; i < n; i++) vis[i] = 0;
	while (S.size()) {
		int u = S.top();
		S.pop();
		if (!vis[u]) scc(u, u);
	}
}

int c[MAX];
ll qtd[MAX];
set<int> adj[MAX];
ll dp[MAX];

ll dfs2(int v) {
	if(dp[v]!=-1) return dp[v];
	dp[v] = 0;
	for(auto u:adj[v]) dp[v] = max(dp[v],dfs2(u));
	dp[v]+=qtd[v];
	return dp[v];
}

int main() { _
	int m;
	cin >> n >> m;

	for(int i=0;i<n;i++) cin >> c[i];

	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		g[a].push_back(b);
		gi[b].push_back(a);
	}

	kosaraju();
	for(int i=0;i<n;i++) dp[i] = -1;
	for(int i=0;i<n;i++) qtd[i] = 0;
	for(int i=0;i<n;i++) {
		qtd[comp[i]]+=c[i];

		for(auto j:g[i]) if(comp[i]!=comp[j]) adj[comp[i]].insert(comp[j]);
	}

	ll ans = 0;
	for(int i=0;i<n;i++) if(i==comp[i]) ans = max(ans,dfs2(i));

	cout << ans << '\n';

	return 0;
}
