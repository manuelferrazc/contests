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

	string s;
	cin >> s;

	int ans=0;

	for(int i=0;i<n;i+=k) {
		bool ok = false;
		for(int j=0;j<k;j++) {
			if(s[i+j]=='0') ok = true;
		}

		if(not ok) ans++;
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
