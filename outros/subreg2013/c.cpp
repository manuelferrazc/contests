#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void dfs(vector<int> *adj, vector<bool> &vis, int i, vector<vector<bool>> &manager, int root) {
	manager[i][root] = true;
	vis[i] = true;

	for(auto u: adj[i]) {
		if(vis[u]==false) dfs(adj,vis,u,manager,root);
	}
}

int main() { _
	int n,m,q;
	cin >> n >> m >> q;

	int age[n];
	for(int i=0;i<n;i++) cin >> age[i];

	vector<int> adj[n];
	int id[n];
	iota(id,id+n,0);

	while(m--) {
		int x,y;
		cin >> x >> y;
		adj[x-1].push_back(y-1);
	}

	vector<vector<bool>> manager(n,vector<bool>(n,false));

	for(int i=0;i<n;i++) {
		vector<bool> vis(n,false);
		dfs(adj,vis,i,manager,i);
		//cout << "vertice = " << i << "sla\n";
		//for(int j=0;j<n;j++) if(manager[i][j]) cout << j << ' ';
		//cout << '\n';
	}

	while(q--) {
		string op;
		cin >> op;

		if(op[0]=='T') {
			int a,b;
			cin >> a >> b;
			a--;
			b--;

			int pa = -1, pb = -1;
			for(int i=0;i<n;i++) {
				if(id[i]==a) pa = i;
				else if(id[i]==b) pb = i;
			}
			swap(id[pa],id[pb]);
		} else {
			int d;
			cin >> d;
			d--;

			int ans = INT_MAX;
			int d2=0;
			for(int i=0;i<n;i++) if(id[i]==d) d2 = i;
		
			for(int i=0;i<n;i++) {	
				if(id[i]==d) continue;
				if(manager[d2][i]) ans = min(ans,age[id[i]]);
			}
			//cout << '\n';

			if(ans==INT_MAX) cout << '*' << '\n';
			else cout << ans << '\n';
		}
	}

	return 0;
}
