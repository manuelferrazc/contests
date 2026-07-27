#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;



int main() { _
	int n,r;
	cin >> n >> r;

	vector<bool> v(n+1,true);

	while(r--) {
		int x;
		cin >> x;
		v[x] = false;
	}

	bool ok = false;
	for(int i=1;i<=n;i++) if(v[i]) {
		cout << i << ' ';
		ok = true;
	}

	if(ok) cout << '\n';
	else cout << "*\n";

	return 0;
}
