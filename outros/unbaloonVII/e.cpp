#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n;
	cin >> n;

	ll dp[n+3];

	dp[n+1] = 0;
	dp[n+2] = 0;

	for(int i=n;i;i--) {
		dp[i] = max(i+dp[i+2],dp[i+1]);
	}

	cout << dp[1] << '\n';

	return 0;
}
