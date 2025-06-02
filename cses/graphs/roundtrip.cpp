#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> ans;
int s=-1;

bool dfs(vector<vector<int>> &adj, vector<bool> &vis, int v,int p=-1) {
	vis[v] = true;

	for(int u:adj[v]) {
		if(u==p) continue;
		if(vis[u]) {
			ans.push_back(u);
			ans.push_back(v);
			s=u;
			return true;
		}

		if(dfs(adj,vis,u,v)) {
			if(s==-1) return true;
			ans.push_back(v);

			if(s==v) s=-1;
			return true;
		}
	}
	return false;
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

	for(int i=0;i<n;i++) {
		if(vis[i]==0) {
			if(dfs(adj,vis,i)) {
				cout << ans.size() << '\n';
				for(int ii:ans) cout << ii+1 << ' ';
				return 0;
			}
		}
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
