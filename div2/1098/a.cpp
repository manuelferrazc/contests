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

	int q[3];
	fill(q,q+3,0);

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		q[x]++;
	}

	int ans = 0;

	for(int fds = 0;fds<=min(q[1],q[2]);fds++) {
		int x = fds;
		x += (q[1]-fds)/3;
		x += (q[2]-fds)/3;
		x += q[0];

		ans = max(ans,x);
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
