#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n;
	cin >> n;

	string s;
	cin >> s;

	char E = 'E';
	char C = 'C';
	char D = 'D';

	int dp[n][3];
	// 0 -> esq, 1 -> meio, 2 -> dir
	dp[0][0] = s[0]==E;
	dp[0][1] = s[0]==C;
	dp[0][2] = s[0]==D;

	for(int i=1;i<n;i++) {
		dp[i][0] = (s[i]==E) + max(dp[i-1][0],dp[i-1][1]);
		dp[i][1] = (s[i]==C) + max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
		dp[i][2] = (s[i]==D) + max(dp[i-1][1],dp[i-1][2]);
	}

	cout << max({dp[n-1][0],dp[n-1][1],dp[n-1][2]}) << '\n';

	return 0;
}
