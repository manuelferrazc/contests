#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

set<int> adj[100'000];
queue<int> q;

void no() {
	cout << "IMPOSSIBLE\n";
	exit(0);
}

void find(int v) {
	if(q.size() and v==q.front()) return;
	q.push(v);

	if(adj[v].empty()) no();

	int u = *adj[v].begin();
	if(adj[u].count(v) != adj[v].count(u)) cout << "esquisito\n";
	adj[v].erase(u);
	adj[u].erase(v);

	find(u);
}

int main() { _
    int n,m;
	cin >> n >> m;

	for(int i=0;i<m;i++) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		adj[a].insert(b);
		adj[b].insert(a);
	}
	
	vector<bool> vis(n,false);
	list<int> path;
	find(0);
	while(q.size()) {
		path.push_back(q.front());
		q.pop();
	}
	// cout << '\n';

	path.push_back(0);
	// for(int i:path) cout <<i+1 << ' ';
	// cout << '\n';
	vis[0] = 1;

	for(auto it = next(path.begin());it!=path.end();) {
		// cout << *it+1 << ' ';
		vis[*it] = true;

		if(adj[*it].size()) {
			find(*it);
			auto aux = it;
			it--;

			while(q.size()) {
				path.insert(aux,q.front());
				q.pop();
			}
		} else it++;
	}
	// cout << '\n';

	// for(int i=0;i<n;i++) cout << vis[i] << ' ';
	// cout << '\n';
	for(int i=0;i<n;i++) if(adj[i].size()) no();

	for(int i:path) cout << i+1 << ' ';
	cout << '\n';

	return 0;
}
