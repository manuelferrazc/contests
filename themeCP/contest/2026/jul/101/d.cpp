#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,k,m;
	string s;
	cin >> n >> k >> m >> s;

	bool dp[m][n+1];
	int first[k];
	for(int i=0;i<k;i++) first[i] = -1;
	for(int i=m-1;i>=0;i--) {
		dp[i][1] = true;
		for(int j=2;j<=n;j++) {
			dp[i][j] = true;
			for(int l=0;l<k;l++) {
				if(first[l]==-1 or dp[first[l]][j-1]==false) {
					dp[i][j] = false;
					break;
				}
			}
		}

		first[s[i]-'a'] = i;
	}
	//cout << "\n\n\n";

	for(int l=0;l<k;l++) if(first[l]==-1 or not dp[first[l]][n]) {
		string ans;

		ans.push_back('a'+l);
		n--;
		int i = first[l];
		//cout << "first = " << i << '\n';

		while(i>=0) {
			int mask = 0;
			for(i++;i<m;i++) {
				if((mask&(1<<(s[i]-'a')))==0) {
					mask += 1<<(s[i]-'a');
					if(dp[i][n]==false) {
						//cout << ' ' <<  i;
						ans.push_back(s[i]);
						n--;
						break;
					}
				}

				if(i==m-1 and n>0) {
					for(int l2=0;l2<k;l2++) {
						if((mask&(1<<l2))==0) {
							ans.push_back('a'+l2);
							n--;
							break;
						}
					}
				}
			}

			if(n==0 or i==m) break;
		}
		//cout << "\n s agr e " << ans << '\n';
		while(n--) ans.push_back('a');

		cout << "no\n" << ans << '\n';
		return;
	}

	cout << "yes\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
