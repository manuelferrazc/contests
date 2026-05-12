#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 200'000

vector<int> adj[MAX];
int qtd[MAX];
int diff[MAX];

int dfs(int v, int p) {
	qtd[v] = (adj[v].size()==1ull);
	for(int u:adj[v]) if(u!=p) qtd[v] += dfs(u,v);
	return qtd[v];
}

void dfs2(int v, int p, int imp, int pa) {
	if(qtd[v]&1) imp++;
	else pa++;

	diff[v] = imp-pa;

	for(int u:adj[v]) if(u!=p) dfs2(u,v,imp,pa);
}

void solve() {
	int n;
	cin >> n;
	
	for(int i=1;i<n;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int root = 0;
	for(int i=0;i<n;i++) {
		if(adj[i].size()>1ull) {
			root = i;
			break;
		}
	}

	dfs(root,-1);
	for(int u:adj[root]) dfs2(u,root,0,0);

	int ans = 0;
	for(int i=0;i<n;i++) if(i!=root and (qtd[i]&1)) ans++;
	
	if(qtd[root]&1) {
		int mx = -1000000;
		for(int i=0;i<n;i++) if(i!=root) mx = max(mx,diff[i]);
		ans -= mx;
	}

	cout << ans << '\n';
	for(int i=0;i<n;i++) adj[i].clear();
	for(int i=0;i<n;i++) qtd[i] = 0;
	for(int i=0;i<n;i++) diff[i] = 0;
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
