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

	int ans[n];
	int ma = n, mi = 1;

	for(int i=0;i<k;i++) {
		int *v,s;
		if(i%2==0) v = &ma, s = -1;
		else v = &mi, s = 1;

		for(int j=i;j<n;j+=k) {
			ans[j] = *v;
			*v += s;
		}
	}

	for(int i=0;i<n;i++) cout << ans[i] << ' ';
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
