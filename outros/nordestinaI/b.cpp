#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void print(int x) {
	for(int i=0;i<3;i++) cout << ((x>>(2-i))&1) ;
	cout << '\n';
}

int main() { _
	int v[8];
	v[0] = 0;
	v[1] = 1;
	v[2] = 3;
	v[3] = 2;
	v[4] = 6;
	v[5] = 7;
	v[6] = 5;
	v[7] = 4;

	string s;
	cin >> s;

	int x = 0;
	for(int i=0;i<3;i++) if(s[2-i]=='1') x+=1<<i;

	for(int i=0;i<8;i++) {
		if(x==v[i]) {
			for(int j=0;j<=8;j++) print(v[(i+j)%8]);
			break;
		}
	}
	exit(0);
}
