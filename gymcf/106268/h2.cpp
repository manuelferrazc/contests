#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using ll = long long int;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

void no() {
	cout << "no\n";
}

void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	
	string v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(v[i][j]=='.') continue;
			
			if(i+k>n or j+k>m) return no();
			if(v[i][j+k-1]!='#' or v[i+k-1][j]!='#' or v[i+k-1][j+k-1]!='#') return no();

			int up = 1, down = 1, left = 1, right = 1;

			for(int i2 = i+1; i2<i+k-1; i2++) if(v[i2][j]=='.') left = 0;
			for(int i2 = i+1; i2<i+k-1; i2++) if(v[i2][j+k-1]=='.') right = 0;

			for(int j2 = j+1; j2<j+k-1; j2++) if(v[i][j2]=='.') up = 0;
			for(int j2 = j+1; j2<j+k-1; j2++) if(v[i+k-1][j2]=='.') down = 0;

			if(up+down+left+right!=3) return no();

			for(int i2=i;i2<=i+k-1;i2++) {
				if(left) v[i2][j] = '.';
				if(right) v[i2][j+k-1] = '.';
			}

			for(int j2 = j; j2<=j+k-1; j2++) {
				if(up) v[i][j2] = '.';
				if(down) v[i+k-1][j2] = '.';
			}
		}
	}

	cout << "yes\n";
}

signed main(){_
	int t;
	cin >> t;

	while(t--) solve();

	return 0;
}


