#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define MAX 500


int main() { _
	int n;
	cin >> n;

	int p[n];
	for(int i=0;i<n;i++) cin >> p[i];

	int dp[n][n];
	for(int i=0;i<n;i++) {
		dp[i][i] = 0;
		if(i<n-1) dp[i][i+1] = 0;
	}

	for(int len=3;len<=n;len++) {
		for(int i=0;i+len-1<n;i++) {
			int j = i+len-1;

			dp[i][j] = 0;
			vector<int> map(n);
			string sub;
			for(int k=0;k<n;k++) if(p[k]>=i and p[k]<=j) {
				map[p[k]] = sub.size();
				sub.push_back('d');
			}

			int inv = 0;

			for(int k=i;k<=j;k++) {
				if(map[k]==0) {
					if(sub[1]=='e') inv--;
				} else if(map[k]==len-1) {
					if(sub[len-2]=='e') inv--;
				} else {
					char menos = sub[map[k]-1];
					char mais = sub[map[k]+1];

					if(menos=='e' and mais=='e') inv-=2;
				}

				int dp2 = inv;
				if(k>i) dp2 += dp[i][k-1];
				if(k<j) dp2 += dp[k+1][j];

				dp[i][j] = max(dp[i][j],dp2);

				sub[map[k]] = 'e';
				
				if(map[k]==0) {
					if(sub[1]=='d') inv++;
				} else if(map[k]==len-1) {
					if(sub[len-2]=='d') inv++;
				} else {
					char menos = sub[map[k]-1];
					char mais = sub[map[k]+1];

					if(menos=='d' and mais=='d') inv+=2;
				}
			}

		}
	}

	cout << dp[0][n-1] << '\n';
	return 0;
}
