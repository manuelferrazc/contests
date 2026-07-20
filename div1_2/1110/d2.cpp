#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "No\n";
}

bool adj[100][100];

bool check(int *a, int n) {
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			if(adj[i][j] != (a[i]+a[j]>=0)) return false;
		}
	}
	return true;
}

bool brute(int *a, int n, int i) {
	if(i==n) return check(a,n);

	for(int k=-5;k<=5;k++) {
		a[i] = k;
		if(brute(a,n,i+1)) return true;
	}

	return false;
}

void solve() {
	int n,m;
	cin >> n >> m;

	for(int i=0;i<m;i++) {
		int o,a,b;
		cin >> o >> a >> b;
		a--;
		b--;

		adj[a][b] = adj[b][a] = (o==1); //1 = nao negativo
	}

	int a[n];
	if(brute(a,n,0)) cout << "Yes\n";
	else cout << "No\n";

	//for(int i=0;i<n;i++) cout << ans[i] << ' ';
	//cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
