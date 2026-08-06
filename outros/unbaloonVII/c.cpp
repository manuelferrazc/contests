#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef long double ld;

int main() { _
	ll b,h,l;
	cin >> b >> h >> l;

	ld area = 3*l*l*sqrtl(3)/(ld)2.0;

	cout << fixed << setprecision(10) << area/(b*h) << '\n';

	return 0;
}
