#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef long double ld;

int main() { _
	int n,a,b;
	cin >> n >> a >> b;

	ld dp[n][6*n+1];
	dp[0][0] = 0;
	for(int i=1;i<7;i++) dp[0][i] = 1/6.0;
	for(int i=7;i<=6*n;i++) dp[0][i] = 0;

	for(int i=1;i<n;i++) {
		dp[i][0] = 0;

		for(int q=1;q<=6*(i+1);q++) {
			dp[i][q] = 0;
			for(int d=1;d<7;d++) if(d<=q) dp[i][q] += dp[i-1][q-d]/6;
		}
		for(int q = 6*(i+1)+1;q<=6*n;q++) dp[i][q] = 0;
	}

	ld ans = 0;
	for(int i=a;i<=b;i++) ans += dp[n-1][i];

	cout << fixed << setprecision(6) << ans << '\n';

	return 0;
}
