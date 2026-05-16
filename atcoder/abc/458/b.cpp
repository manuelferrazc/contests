#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n,m;
	cin >> n >> m;

	pair<int,int> dd[] = {{1,0},{-1,0},{0,1},{0,-1}};

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			int qtd = 0;
			for(auto [dx,dy]:dd) {
				int x = i+dx, y=j+dy;
				if(x>=0 and x<n and y>=0 and y<m) qtd++;
			}
			cout << qtd << ' ';
		}
		cout << '\n';
	}

	return 0;
}
