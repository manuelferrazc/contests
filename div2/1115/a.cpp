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

	map<int,int> m;
	int x;
	for(int i=0;i<n;i++) {
		cin >> x;
		m[x]++;
	}

	multimap<int,int> m2;
	for(auto [a,b]:m) m2.insert({b,a});

	int ans = 0;

	int last = 0;
	while(m2.size()) {
		auto it = prev(m2.end());
		if(it->ss==last) {
			auto [b,a] = *it;
			m2.erase(it);
			if(m2.empty()) {
				ans+=a;
				break;
			}

			auto it2 = prev(m2.end());
			m2.insert({b,a});
			last = it2->ss;
			ans+=it2->ss;

			int bb = it2->ff;
			a = it2->ss;
			m2.erase(it2);
			if(bb>1) m2.insert({bb-1,a});
		} else {
			last = it->ss;
			ans+=it->ss;
			auto [b,a] = *it;
			m2.erase(it);
			if(b>1) m2.insert({b-1,a});
		}
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
