#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	string s;
	int n;
	cin >> s >> n;

	for(int i=n;i<(int)s.size()-n;i++) cout << s[i];
	cout << '\n';

	return 0;
}
