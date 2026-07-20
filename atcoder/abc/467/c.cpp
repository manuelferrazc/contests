#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,m;
	cin >> n >> m;

	int a[n],b[n-1];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n-1;i++) cin >> b[i];

	int ans = 0;

	int dp[n][2];
	if((a[n-2]+a[n-1])%2==b[n-2]) {
		dp[n-2][0] = 0;
		dp[n-2][1] = 2;
	} else {
		dp[n-2][0] = 1;
		dp[n-2][1] = 1;
	}

	//cout << dp[0][0] << ' ' << dp[0][1] << ' ' << dp[0][2] << '\n';
	for(int i=n-3;i>=0;i--) {
		if((a[i]+a[i+1])%2==b[i]) {
			dp[i][0] = dp[i+1][0];
			dp[i][1] = dp[i+1][1]+1;
		} else {
			dp[i][0] = dp[i+1][1];
			dp[i][1] = dp[i+1][0]+1;
		}
		//cout << dp[i][0] << ' ' << dp[i][1] << ' ' << dp[i][2] << '\n';
	}

	cout << min(dp[0][0],dp[0][1]) << '\n';

    return 0;
}
