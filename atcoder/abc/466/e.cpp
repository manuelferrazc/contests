#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,k;
	cin >> n >> k;

	int a[n];
	int b[n];
	for(int i=0;i<n;i++) cin >> a[i] >> b[i];

	ll dp[n][2];
	dp[0][0] = a[0];
	dp[0][1] = LLONG_MIN;

	for(int i=1;i<n;i++) {
		dp[i][0] = dp[i-1][0]+a[i];
		dp[i][1] = LLONG_MIN;
	}

	ll ans = dp[n-1][0];

	while(k--) {
		ll dp2[n][2];
		dp2[0][0] = a[0];
		dp2[0][1] = b[0];
		for(int i=1;i<n;i++) {
			dp2[i][0] = max(dp2[i-1][0],dp2[i-1][1]) + a[i];
			dp2[i][1] = max(dp2[i-1][1],dp[i-1][0]) + b[i];
		}

		ans = max({ans,dp2[n-1][0],dp2[n-1][1]});

		for(int i=0;i<n;i++) {
			dp[i][0] = dp2[i][0];
			dp[i][1] = dp2[i][1];
		}
	}

	cout << ans << '\n';

    return 0;
}
