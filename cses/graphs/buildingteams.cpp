#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool dfs(vector<vector<int>> &adj, vector<int> &team, int v) {
	for(int u:adj[v]) {
		if(team[u]==team[v]) {
			return false;
		}
		if(team[u]==0) {
			team[u] = team[v]^3;
			if(dfs(adj,team,u)==false) return false;
		}
	}
	return true;
}

int main() { _
    int n,m;
	cin >> n >> m;
	vector<int> team(n,0);
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
		if(team[i]==0) {
			team[i] = 1;
			if(dfs(adj,team,i)==false) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
	}

	for(int i:team) cout << i << ' ';
	cout << '\n';

	return 0;
}
