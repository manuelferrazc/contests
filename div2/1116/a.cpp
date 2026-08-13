#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int a[3];
	cin >> a[0] >> a[1] >> a[2];
	sort(a,a+3);

	int ans = a[2]-a[0];
	ans = min(ans,a[1]);
	ans = min(ans,a[1]+a[2] - a[0]);

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
