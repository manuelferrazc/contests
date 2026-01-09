#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> cc;
vector<vector<int>> cks;
array<int,3> v[200000]; // v[i][0] -> se pertence à um ciclo, [1] -> em qual ciclo tá, [2] -> qual indice
short color[200'000];
int to[200'000];
vector<int> adj[200'000];
int ans[200'000];

int dfs(int u) {
	if(color[u]==1) return u;
	else if(color[u]==2) return -1;

	color[u] = 1;

	int r = dfs(to[u]);
	color[u] = 2;

	if(r!=-1) {
		v[u][0] = 1;
		v[u][1] = cks.size();
		cc.push_back(u);
		
		if(r==u) {
			reverse(cc.begin(),cc.end());
			for(int i=0;i<(int)cc.size();i++) {
				v[cc[i]][2] = i;
				ans[cc[i]] = cc.size();
			}
			cks.push_back(cc);
			cc.clear();

			return -1;
		}

		return r;
	}
	return -1;	
}

void dfs2(int u, int qtd) {
	ans[u] = qtd;
	for(auto u2:adj[u]) dfs2(u2,qtd+1);
}

int main() { 
    int n;
	cin >> n;
	
	for(int i=0;i<n;i++) color[i] = 0;

	for(int i=0;i<n;i++) {
		cin >> to[i];
		to[i]--;
		adj[to[i]].push_back(i);

		if(to[i]==i) {
			color[i] = 2;
			v[i][0] = 1;
			v[i][1] = cks.size();
			v[i][2] = 0;
			cks.push_back({i});
			ans[i] = 1;
		} else v[i][0] = 0;
	}

	for(int i=0;i<n;i++) 
		if(color[i]==0) dfs(i);

	for(int i=0;i<n;i++) 
		if(v[i][0]==0 and v[to[i]][0]) 
			dfs2(i,cks[v[to[i]][1]].size()+1);

	for(int i=0;i<n;i++) cout << i[ans] << ' ';
	cout << '\n';

	return 0;
}
