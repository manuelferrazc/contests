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
	for(int i=0;i<n;i++) {
		int a; cin >> a;
		m[a]++;
	}


	while(m.size()) {
		auto [mx,qtd] = *m.rbegin();

		for(int i=0;i<qtd;i++) cout << mx << ' ';

		m.erase(mx);
		auto it = m.begin();

		while(it!=m.end()) {
			auto [val,q2] = *it;

			for(int i=0;i<min(q2,qtd);i++) cout << val << ' ';

			it->ss-=min(q2,qtd);
			auto it2 = it;
			it++;

			if(it2->ss==0) m.erase(it2);
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
