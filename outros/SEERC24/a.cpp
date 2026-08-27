#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> adj[1000];

vector<array<int,3>> ans;

void dfs(int x, int y, int z) {
	if(x!=y) ans.push_back({x,y,z});
	for(int u:adj[z]) if(u!=y)dfs(x,z,u);
}

void check(int v) {
	ans.clear();

	for(int u:adj[v]) dfs(v,v,u);
}

int main() { _
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

	int i=0;
	vector<array<int,3>> v;
	for(;i<n;i++) {
		check(i);
		if(v.empty() or ans.size()<v.size()) v = ans;
		
	}

	cout << v.size() << '\n';
	for(auto [a,b,c]:v) {
		cout << a+1 << ' ' << b+1 << ' ' << c+1 << '\n';
	}


	exit(0);
}
