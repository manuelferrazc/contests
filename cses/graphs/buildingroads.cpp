#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<vector<int>> &adj, vector<bool> &vis, int v) {
	vis[v] = true;
	for(int u:adj[v]) {
		if(not vis[u]) dfs(adj,vis,u);
	}
}

int main() { _
    int n,m;
	cin >> n >> m;
	vector<bool> vis(n,false);
	vector<vector<int>> adj(n);


	while(m--) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<pair<int,int>> ans;
	dfs(adj,vis,0);

	for(int i=1;i<n;i++) {
		if(not vis[i]) {
			ans.push_back(make_pair(1,i+1));
			dfs(adj,vis,i);
		}
	}

	cout << ans.size() << '\n';
	for(const auto &i:ans) cout << i.ff << ' ' << i.ss << '\n';

	return 0;
}
