#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
const int MAX = 100'000;

ll dp[MAX];
vector<int> adj[MAX];

ll ddp(int v) {
	if(dp[v]!=-1) return dp[v];

	dp[v] = 0;
	for(int u:adj[v]) 
		dp[v]+=ddp(u);
	
	dp[v]%=mod;

	return dp[v];
}

int main() { _
    int n,m;
	cin >> n >> m;

	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	for(int i=0;i<n;i++) dp[i] = -1;
	dp[n-1] = 1;

	cout << ddp(0) << '\n';

	return 0;
}
