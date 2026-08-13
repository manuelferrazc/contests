#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int ans = 0;
	for(int shift = 0;shift<4;shift++) {
		int val = shift;
		bool ok = true;
		for(int i=0;i<n;i++, val = (val+1)%4) {
			if(val<2 and s[i]=='1' or val>1 and s[i]=='0') {
				ok = false;
				break;
			}
		}
		if(ok) ans++;
	}

	cout << ans << '\n';
}

int main() { 

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
