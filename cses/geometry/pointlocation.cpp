#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int t;
	cin >> t;
	while(t--) {
		ll x[5],y[5];
		cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2];
		x[3] = x[1]-x[0];
		x[4] = x[2]-x[1];
		y[3] = y[1]-y[0];
		y[4] = y[2]-1[y];

		ll d = x[3]*y[4]-y[3]*x[4];
		if(d==0) cout << "TOUCH\n";
		else if(d>0) cout << "LEFT\n";
		else cout << "RIGHT\n";
	}

	return 0;
}
