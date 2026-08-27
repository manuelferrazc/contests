#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

//typedef long long ll;
typedef long double ld;

int main() { _
	int N;
	ld p;

	cin >> N >> p;
	p/=100.0;

	vector<vector<ld>> dp(2050,vector<ld>(2050));
	for(int i=0;i<2050;i++) dp[i][i] = 0;
	
	ld um = 1.0;

	for(int n = 2026;n>=N;n--) {
		for(int k=n-1;k>=0;k--) {
			ld kn = k/(ld)n;
			ld kn1 = k/(ld)(n+um);

			ld nkn = um - kn;
			ld nkn1 = um - kn1;

			if(n==2026) {
				ld num = um + nkn*dp[k+1][n];
				ld den = um-kn;

				dp[k][n] = num/den;
			} else {
				ld f1 = p * (kn1*dp[k][n+1] + nkn1*dp[k+1][n+1]);
				ld f2 = (um - p) * nkn * dp[k+1][n];
	
				ld num = um+f1+f2;
				ld den = um + (p-um)*kn;

				dp[k][n] = num/den;
			}
		}
	}

	//for(int i=

	cout << fixed << setprecision(10);
	cout << dp[0][N] << '\n';

	//for(int i=N;i<=N+5;i++) {
	//	cout << i << ": ";
	//	for(int k=1;k<=i;k++) cout << dp[k][i] << ' ';
	//	cout << '\n';
	//}

	exit(0);
}
