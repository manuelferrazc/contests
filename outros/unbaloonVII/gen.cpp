#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
#define int ll

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l,r);
	return uid(rng);
}

signed main() { _
	int n = 1'000'000'000'000ll;
	int q = 100'000;

	cout<< n << ' ' << q << '\n';

	while(q--) {
		int op = uniform(1,2);
		int l = uniform(1,n);
		int r = uniform(l,n);

		if(op==1) cout << op << ' ' << l << ' ' << r << '\n';
		else cout << op << ' ' << l << ' ' << r << ' ' << uniform(1,n) << ' ' << uniform(1,n) << '\n';
	}

	return 0;
}
