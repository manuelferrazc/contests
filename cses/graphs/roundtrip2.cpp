#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 100'000

vector<int> adj[MAX];
int color[MAX];

vector<int> ans;

int dfs(int v) {
	if(color[v]==1) {
		ans.push_back(v);
		return v;
	} else if(color[v]==2) return -1;

	color[v] = 1;

	for(auto u:adj[v]) {
		int r = dfs(u);
		if(r==-1) continue;
		else if(r==-2) return -2;
		else {
			ans.push_back(v);
			if(v==r) return -2;
			else return r;
		}
	}

	color[v] = 2;

	return -1;
}

int main() { _
    int n,m;
	cin >> n >> m;

	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for(int i=0;i<n;i++) color[i] = 0;

	for(int i=0;i<n;i++) {
		if(dfs(i)==-2) {
			cout << ans.size() << '\n';
			for(auto it = ans.rbegin();it!=ans.rend();it++) cout << *it+1 << ' ';
			cout << '\n';
			return 0;
		} 
	}

	cout << "IMPOSSIBLE\n";

	return 0;
}
