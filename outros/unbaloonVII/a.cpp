#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

#define MAX 100'000
int c[MAX];
map<int,int> m;
int ans[MAX];
vector<int> adj[MAX];

void dfs(int v, int p) {
	m[c[v]]++;
	ans[v] = m.size();

	for(int u:adj[v]) if(u!=p) dfs(u,v);

	if((--m[c[v]])==0) m.erase(c[v]);
}	

int main() { _
	int n,q;
	cin >> n >> q;

	for(int i=0;i<n;i++) cin >> c[i];
	
	for(int i=1;i<n;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(0,-1);

	while(q--) {
		int x;
		cin >> x;
		cout << ans[x-1] << '\n';
	}

	return 0;
}
