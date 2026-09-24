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
	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	for(int i=0;i<n;i++) {
		if(v[i]) {
			v[i] = 1;
			break;
		}
	}

	for(int i=n-1;i>=0;i--) {
		if(v[i]) {
			v[i] = 1;
			break;
		}
	}

	for(int i=0;i<n;i++) cout << max(v[i],0) << ' ';
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
