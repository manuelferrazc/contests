#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<int> adj[100'000];
int dp[100'000];
int to[100'000];

int ddp(int v) {
	if(dp[v]!=-1) return dp[v];

	dp[v] = INT_MIN;
	for(auto u:adj[v]) {
		int r = ddp(u);
		if(r>dp[v]) {
			dp[v] = r;
			to[v] = u;
		}
	}

	if(dp[v]!=INT_MIN) dp[v]++;
	return dp[v];
}


int main() { _
	cin >> n >> m;

	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for(int i=0;i<n;i++) dp[i] = -1;
	dp[n-1] = 1;

	ddp(0);
	if(dp[0]==INT_MIN) cout << "IMPOSSIBLE\n";
	else {
		cout << dp[0] << '\n' << 1 << ' ';
		int v=0;
		while(v!=n-1) {
			v = to[v];
			cout << v+1 << ' ';
		}
		cout << '\n';	
	}

	return 0;
}
