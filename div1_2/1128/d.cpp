#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,m;
	cin >> n >> m;

	if(n==1) {
		cout << 0 << '\n';
		return;
	}

	vector<pair<int,int>> ans;
	ans.push_back({1,(n+1)/2});
	int l = 2;
	int r = n-1;
	while(l<=r) {
		ans.push_back({l,r});
		l++;
		r--;
	}

	cout << ans.size() << '\n';
	for(auto [a,b]:ans) cout << a << ' ' << b << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
