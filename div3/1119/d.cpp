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

	map<int,vector<char>> ans;
	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	map<int,int> c;
	for(int i:v) c[i]++;
	if(c.count(0)==1ull and c[0]==1) {
		cout << "NO\n";
		return;
	}

	int mx;
	for(mx=0;;mx++) {
		if(c.find(mx)==c.end() or c[mx]==1) break;
		
		int q = c[mx];
		ans[mx].push_back('A');
		ans[mx].push_back('B');
		q-=2;
		while(q--) ans[mx].push_back('A');
	}

	for(auto it = c.lower_bound(mx);it!=c.end();it++) {
		auto [val,qtd] = *it;
		while(qtd--) ans[val].push_back('C');
	}

	cout << "YES\n";
	for(int i:v) {
		cout << ans[i].back();
		ans[i].pop_back();
	}

	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
