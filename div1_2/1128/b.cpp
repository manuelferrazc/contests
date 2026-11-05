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

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	int ans = v[0];

	for(int i=1;i<n;i++) {
		if(v[i]==v[i-1]) {
			ans |= v[i];
			continue;
		}

		for(int j=30;;j--) {
			int b1 = (v[i]>>j)&1;
			int b2 = (v[i-1]>>j)&1;

			if(b1!=b2) {
				ans |= max(v[i],v[i-1]);
				ans |= (1<<j)-1;
				break;
			}
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
