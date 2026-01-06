#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 2500
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int n, m;
ll d[MAX];
vector<pair<int, int>> ar; // vetor de arestas
vector<int> w;              // peso das arestas

set<int> neg;
vector<int> neg2;

bool bellman_ford(int a) {
	bool ret = 0;
	for (int i = 0; i <= n; i++)
	for (int j = 0; j < m; j++) {
		if (d[ar[j].second] > d[ar[j].first] + w[j]) {
				if (i == n) {
					neg.insert(ar[j].ff);
					ret = 1;
				}

			d[ar[j].second] = d[ar[j].first] + w[j];
		}
	}

	return ret;
}

bool vis[MAX];
vector<int> adj[MAX];

void dfs1(int v) {
	vis[v] = true;
	if(neg.count(v)) {
		neg2.push_back(v);
		neg.erase(v);
	}

	for(int u:adj[v]) {
		if(vis[u]==false) dfs1(u);
	}
}


bool dfs2(int v) {
	if(v==n-1) return true;
	if(vis[v]) return false;
	vis[v] = true;

	for(int u:adj[v]) if(dfs2(u)) return true;
	return false;
}

int main() { _
    cin >> n >> m;
	for (int i = 0; i < n; i++) d[i] = LINF;
	for (int i = 0; i < n; i++) vis[i] = 0;
	d[0] = 0;

	for(int i=0;i<m;i++) {
		int a,b,c;
		cin >> a >> b >> c;
		a--;
		b--;

		ar.push_back(pair(a,b));
		w.push_back(-c);
		
		adj[a].push_back(b);
	}

	if(bellman_ford(0)==0) cout << -d[n-1] << '\n';
	else {
		dfs1(0);
		for (int i = 0; i < n; i++) vis[i] = 0;

		bool err = false;
		for(int v:neg2) {
			// cout << "neg2: " << v << '\n';
			if(dfs2(v)) {
				err = true;
				break;
			}
		}

		if(err) cout << -1 << '\n';
		else cout << -d[n-1] << '\n';
	}


	return 0;
}
