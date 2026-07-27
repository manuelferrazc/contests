#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;



int main() { _
	int a,b,c;
	cin >> a >> b >> c;

	if(a!=b and a!=c) cout << 'A';
	else if(b!=a and b!=c) cout << 'B';
	else if(c!=a and c!=b) cout << 'C';
	else cout << '*';

	cout << '\n';

	return 0;
}
