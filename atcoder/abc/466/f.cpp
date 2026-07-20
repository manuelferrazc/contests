#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll n,x;
	cin >> n >> x;

	ll a;
	cin >> a;

	ll comp = x/a;
	ll ans = comp;
	ll rem = x%a;
	ll qrem = 0;
	if(rem) qrem++;
	n--;

	while(n--) {
		ll na;
		cin >> na;
		if(na>=a) continue;

		ans += ((a-1)/na)*comp;
		ll ncomp = ((a-1)/na)*comp + (rem/na)*qrem;
		ll nrem = ((a-1)%na)*comp + (rem%na)*qrem;
		//ll qrem = 

		a = na;
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;

	while(t--) solve();

    return 0;
}
