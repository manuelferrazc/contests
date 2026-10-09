#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 300'001
#define MAX2 181

ll dp[MAX2][MAX2];
vector<int> fat;
int v[MAX];

vector<int>::iterator m[MAX+1];

int n;

ll ddp(int i,int j) { // x = fat[i]
	if(dp[i][j]!=-1) return dp[i][j];
	if(i==0) return dp[i][j] = 0;

	dp[i][j] = 0;
	int x = fat[i];
	int xant = fat[j];

	for(int k=0;k<n;k++) {
		if(v[k]%x==0 and v[k]%xant!=0) dp[i][j] += v[k];
	}

	vector<bool> vis(fat.size(),false);
	ll best = 0;
	for(int k=0;k<n;k++) {
		int g = gcd(x,v[k]);
		if(v[k]%x and g!=1) {
			int pos = m[g]-fat.begin();

			if(vis[pos]) continue;
			vis[pos] = true;

			best = max(best,ddp(pos,i));
		}
	}

	dp[i][j] += best;

	return dp[i][j];
}

void solve() {
	int x;
	cin >> n >> x;

	fat.clear();
	for(int i=1;i*i<=x;i++) {
		if(x%i==0) {
			fat.push_back(i);
			if(i*i!=x) fat.push_back(x/i);
		}
	}

	sort(fat.begin(),fat.end());

	for(int i=0;i<n;i++) cin >> v[i];

	ll ans = 0;
	for(int i=1;i<fat.size();i++) {
		ll qtd = 0;
		ll g = x;

		for(int j=0;j<n;j++) {
			if(v[j]%fat[i]==0) {
				g = gcd(g,v[j]);
				qtd+=v[j];
			}
		}

		if(g==fat[i]) ans = max(ans,qtd);
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
