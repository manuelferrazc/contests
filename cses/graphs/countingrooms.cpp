#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;
vector<string> v;
const pair<int,int> dd[] = {{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int i, int j) {
	v[i][j] = '#';

	for(const pair<int,int> &d:dd) {
		int x=i+d.ff,y=j+d.ss;
		if(x>=0 and x<n and y>=0 and y<m and v[x][y]=='.') dfs(x,y);
	}
}


int main() { _
	cin >> n >> m;
	v.resize(n);
	for(string &s:v) cin >> s;
	
	int ans=0;
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			if(v[i][j]=='.') {
				dfs(i,j);
				ans++;
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
