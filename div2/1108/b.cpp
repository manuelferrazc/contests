#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	cin >> n;
	
	if(n==1) cout << 1;
	else if(n==2) cout << -1;
	else if(n==3) cout << "1 2 3";
	else {
		cout << "1 2 6 9";
		ll vtnc = 9;
		for(int i=5;i<=n;i++) {
			vtnc <<= 1;
			cout << ' ' << vtnc;
		}
	}

	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
