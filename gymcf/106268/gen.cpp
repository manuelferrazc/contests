#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using ll = long long int;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;


signed main(int argc, char **argv){ 
	srand(atoi(argv[1]));
	
	int n = 5 + rand()%10;
	int m = 5 + rand()%10;
	int k = 5 + rand()%5;

	cout << 1 << ' ' << n << ' ' << m << ' ' << k << '\n';

	vector<vector<char>> v(n,vector<char>(m,'.'));

	//for(int i=0;i+k-1<n;i+=k) {
//		for(int j=0;j+k-1<m;j+=k) {
	//		for(int i2=i;i2<i+k;i2++) v[i2][j] = '#';
//			for(int j2=j+1;j2<j+k;j2++) v[i][j2] = v[i+k-1][j2] = '#';
	//	}
	//}

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) cout << ( rand()&1 ? '#' : '.' );
		cout << '\n';
	}

	return 0;
}


