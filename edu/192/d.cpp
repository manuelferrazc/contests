#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void say(int x) {
	cout << max(x,-1) << '\n';
}

const int maxX = 5'000, maxY = 5'000, mod = 10;

short dp[maxX*maxY*mod];

inline short & get(int i, int j, int k) {
	return dp[i*(maxY*mod) + j*mod + k];
}

void solve() {
	string sa,sb;
	cin >> sa >> sb;

	int na = sa.size(), nb = sb.size();
	int a[na],b[nb];
	for(int i=0;i<na;i++) a[i] = sa[i]-'0';
	for(int i=0;i<nb;i++) b[i] = sb[i]-'0';

	//int dp[na][nb][10];
	for(int i=0;i<na;i++) for(int j=0;j<nb;j++)
		for(int k=0;k<10;k++) get(i,j,k) = -10000;

	int dif = a[0]-b[0]+10;
	dif%=10;
	get(0,0,dif) = 1;
	
	int s = a[0];
	for(int i=1;i<na;i++) {
		s += a[i];
		s%=10;
		get(i,0,(s-b[0]+10)%10) = 1;
		// dp[i][0][(s-b[0]+10)%10] = 1;
	}

	s = b[0];
	for(int i=1;i<nb;i++) {
		s += b[i];
		s %= 10;
		get(0,i,(a[0]-s+10)%10) = 1;
		//dp[0][i][(a[0]-s+10)%10] = 1;
	}

	for(int i=1;i<na;i++) {
		for(int j=1;j<nb;j++) {
			get(i,j,(a[i]-b[j]+10)%10) = get(i-1,j-1,0)+1;
			//dp[i][j][(a[i]-b[j]+10)%10] = dp[i-1][j-1][0]+1;

			for(int m=0;m<10;m++) {
				//dp[i][j][m] = max({
				//	dp[i][j][m],
				//	dp[i-1][j-1][(m-a[i]+b[j]+10)%10],
				//	dp[i][j-1][(m+b[j])%10],
				//	dp[i-1][j][(m-a[i]+10)%10]
				//});
				get(i,j,m) = max({
					get(i  , j  , m),
					get(i-1, j-1, (m-a[i]+b[j]+10)%10),
					get(i  , j-1, (m+b[j])%10),
					get(i-1, j  , (m-a[i]+10)%10)
				});

				//println("i={},j={},m={},dp={}",i,j,m,dp[i][j][m]); 
			}
		}
	}
	//say(dp[na-1][nb-1][0]);
	say(get(na-1,nb-1,0));
	//cout << "\n\n\n";
}

int main() { //_
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
