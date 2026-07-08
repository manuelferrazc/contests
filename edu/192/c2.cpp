#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,k;
	cin >> n >> k;

	map<int,int> m;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	set<ull> ans;
	int qtd = n;
	if(k>=n and (k-n)%m.size()==0) ans.insert(m.size());

	while(m.size()) {
		vector<map<int,int>::iterator> v;
		for(auto it = m.begin();it!=m.end();it++) {
			it->ss--;
			qtd--;
			if(it->ss==0) v.push_back(it);
		}

		for(auto it: v) m.erase(it);
		if(m.empty()) break;

		if(k>=qtd and (k-qtd)%m.size()==0) ans.insert(m.size());
	}

	cout << ans.size() << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
