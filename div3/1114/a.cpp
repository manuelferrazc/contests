#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int a[3],ans=0;
	for(int i=0;i<3;i++) cin >> a[i];

	while(true) {
		sort(a,a+3);
		if(a[0]==a[1] or a[1]==a[2]) break;
		a[0]++;
		a[2]--;
		ans++;
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
