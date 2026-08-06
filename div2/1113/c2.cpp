#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	cin >> n;

	int v[2*n];
	int f[n],s[n];
	fill(f,f+n,-1);

	for(int i=0;i<2*n;i++) {
		int x;
		cin >> x;
		x--;
		v[i] = x;
		if(f[x]==-1) f[x] = i;
		else {
			s[x] = i;
		//	pq.push({i-f[x]+1,x});
		}
	}

	ll dp[2*n][2*n];
	for(int i=0;i<2*n;i++) dp[i][i] = 1;
	for(int sz=1;sz<2*n;sz++) {
		for(int i=0;i+sz<2*n;i++) {
			dp[i][i+sz] = 1+max(dp[i][i+sz-1],dp[i+1][i+sz]);
			for(int j=i+1;j<i+sz;j++) dp[i][i+sz] = max(dp[i][i+sz],1+dp[i][j-1]+dp[j+1][i+sz]);
			for(int j=i;j<=i+sz;j++) {
				if(f[v[j]]==j and s[v[j]]<=i+sz) {
					ll pref = 0;
					if(j>i) pref = dp[i][j-1];
					ll in = s[v[j]]-f[v[j]] +1;
					in *= in;
					ll af = 0;
					if(s[v[j]]<i+sz) af = dp[s[v[j]]+1][i+sz];
					dp[i][i+sz] = max(dp[i][i+sz],pref+in+af);
				}
			}
		}

	}

	cout << dp[0][2*n-1] << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
