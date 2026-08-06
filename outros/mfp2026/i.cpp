#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

bool dfs(vector<pair<int,ll>> *adj, bool *vis, ll must, int v, int tg) {
	if(v==tg) return true;
	vis[v] = true;
	for(auto [u,w]:adj[v]) {
		if((w&must)!=must) continue;
		if(vis[u]==false and dfs(adj,vis,must,u,tg)) return true;
	}
	return false;
}

int main() { _
	int n,m;
	cin >> n >> m;

	vector<pair<int,ll>> adj[n];

	while(m--) {
		int a,b,c;
		cin >> a >> b >> c;
		adj[a-1].push_back(pair(b-1,c));
	}

	bool vis[n];
	fill(vis,vis+n,false);
	if(dfs(adj,vis,0,0,n-1)==false) {
		cout << "-1\n";
		return 0;
	}

	ll ans = 0;

	for(int i=30;i>=0;i--) {
		fill(vis,vis+n,false);
		if(dfs(adj,vis,ans+(1ll<<i),0,n-1)) ans+=1ll<<i;
	}

	cout << ans << '\n';
	return 0;
}
