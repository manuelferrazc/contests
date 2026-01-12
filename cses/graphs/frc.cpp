#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> adj[100'000];
vector<int> adj2[100'000];
int vis1[100'000];
int vis2[100'000];

void no(int a, int b) {
	cout << "NO\n" << a << ' ' << b << '\n';
	exit(0);
}

void dfs(int v, vector<int> *ad, int *vis) {
	vis[v] = true;

	for(auto i:ad[v]) 
		if(not vis[i]) {
			dfs(i,ad,vis);
		}
}

int main() { _
    int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++) vis1[i] = 0;
	for(int i=0;i<n;i++) vis2[i] = 0;

	while(m--) {
		int a,b;
		cin >> a >> b;

		adj[a-1].push_back(b-1);
		adj2[b-1].push_back(a-1);
	}

	dfs(0,adj,vis1);
	dfs(0,adj2,vis2);

	for(int i=1;i<n;i++) if(not vis1[i]) no(1,i+1);
	for(int i=1;i<n;i++) if(not vis2[i]) no(i+1,1);
	cout << "YES\n";

	return 0;
}
