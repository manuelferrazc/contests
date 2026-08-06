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

	multiset<ll> s;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x; s.insert(x);
	}

	vector<ll> a;
	ll sum = 0;

	for(int i=0;i<n;i++) {
		auto it = s.upper_bound(-sum);

		if(it==s.end()) {
			cout << -1 << '\n';
			return;
		}

		sum+=*it;
		a.push_back(sum);

		s.erase(it);
	}

	for(int i=0;i<n;i++) cout << a[i] << ' ';
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
