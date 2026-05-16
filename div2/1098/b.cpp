#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void ans(ll x) {
	cout << x << '\n';
}

void solve() {
	ll n,x1,x2,k;
	cin >> n >> x1 >> x2 >> k;

	if(n<=3) return ans(1);

	ll dist = min(abs(x2-x1),n-max(x2,x1)+min(x1,x2));

	ll ans2 = dist+k;

	ans(ans2);
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
