#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

int main() { _
    int n,m;
	cin >> n >> m;

	vector<int> adj[n];
	while(m--) {
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
	}

	int dp[1<<n][n];
	for(int i=0;i<(1<<n);i++) for(int j=0;j<n;j++) dp[i][j] = 0;

	dp[1][0] = 1;

	for(int i=1;i<(1<<n);i++) {
		for(int j=0;j<n;j++) {
			if(dp[i][j]==0) continue;
			if(i&(1<<j)) {
				for(auto u:adj[j]) {
					if((i&(1<<u))==0) {
						dp[i+(1<<u)][u] += dp[i][j];
						dp[i+(1<<u)][u] %= mod;
					}
				}
			}
		}
	}

	cout << dp[(1<<n)-1][n-1] << '\n';

	return 0;
}
