#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	string s;
	int n;

	cin >> n >> s;

	vector<int> q;
	for(int i=0;i<n;i++) {
		if(s[i]=='#') {
			if(i==0 or s[i-1]=='*') q.push_back(1);
			else q.back()++;
		}
	}

	int ans = 0;

	while(q.size()) {
		int l = q.back();
		q.pop_back();

		int penis = 0;
		while(l>2) {
			penis++;
			l-=2;
		}

		penis++;

		ans = max(ans,penis);
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
