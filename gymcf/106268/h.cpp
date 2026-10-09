#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using ll = long long int;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

const pair<int,int> adj[] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void no() {
	cout << "no\n";
}

int d[1010][1010];

void solve() {
	int n,m,k;
	cin >> n >> m >> k;
	string v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=0;i<n;i++) for(int j=0;j<m;j++) {
		d[i][j] = 0;
		for(auto [a,b]:adj) {
			int x = i+a, y = j+b;
			if(x>=0 and y>=0 and x<n and y<m and v[x][y]=='#') d[i][j]++;
		}
	}

	auto zerar = [&] (int i, int j) -> bool {
		if(v[i][j]=='.') return true;
		for(auto [a,b]:adj) {
			int x = i+a, y=j+b;
			if(x>=0 and y>=0 and x<n and y<m) d[x][y]--;
		}
		v[i][j] = '.';
		return false;
	};

	for(int j=0;j<m;j++) {
		for(int i=0;i<n;i++) {
			if(v[i][j]=='.') continue;

			//for(int it = 0;it<n;it++) cout << v[it] << '\n';
			//cout << '\n';
			if(i+k-1>=n or j+k-1>=m) return no();

			if(d[i][j]==1) {
				if(v[i+1][j]=='#') {
			//		cout << "ababa\n";
					for(int i2 = i; i2<i+k; i2++) if(zerar(i2,j)) return no();
					for(int j2 = j+1;j2<j+k;j2++) if(zerar(i+k-1,j2)) return no();
					for(int i2 = i+k-2;i2>=i;i2--) if(zerar(i2,j+k-1)) return no();
				} else {
			//		cout << "f1\n";
					for(int j2=j; j2<j+k; j2++) if(zerar(i,j2)) return no();
			//		cout << "f2\n";
					for(int i2 = i+1; i2<i+k; i2++) if(zerar(i2,j+k-1)) return no();
			//		cout << "f3\n";
					for(int j2 = j+k-2;j2>=j;j2--) if(zerar(i+k-1,j2)) return no();
				}
			//	cout << "sla\n";
			} else {
				int c1 = 1, c2 = 1;
				for(int j2 = j; j2<j+k; j2++) if(v[i+k-1][j2]=='.') c1 = 0;
				for(int i2 = i; i2<i+k; i2++) if(v[i2][j+k-1]=='.') c2 = 0;
				
				for(int i2 = i;i2<i+k;i2++) if(zerar(i2,j)) return no();
				for(int j2 = j+1; j2<j+k; j2++) if(zerar(i,j2)) return no();

				if(c1==c2) return no();
				if(c1) {
					for(int j2 = j+1; j2<j+k;j2++) zerar(i+k-1,j2);
				} else {
					for(int i2 = i+1; i2<i+k;i2++) zerar(i2,j+k-1);
				}
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


