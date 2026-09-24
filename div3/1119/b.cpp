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
	int ans=0;

	int r0=0,r2=0;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		if(x&1) ans++;
		else if(x%4==0) r0++;
		else r2++;
	}

	cout << max({ans,r0,r2}) << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
