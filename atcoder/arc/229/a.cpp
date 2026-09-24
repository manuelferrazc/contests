#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int x;
	cin >> x;

	string s(50,'C');

	int mx = 49;
	for(int i=0;i<mx and x>0;i++) {
		if(mx-i<=x) {
			x -=  mx-i;
			mx--;
			s[i] = 'A';
		}
	}

	for(char c:s) cout << c << 'R';
	cout << '\n';

	return 0;
}
