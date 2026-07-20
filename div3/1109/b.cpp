#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "NO\n";
}

void solve() {
	int n;
	cin >> n;

	ll v[n+1];
	for(int i=0;i<n;i++) cin >> i[v];

	for(int i=1;i<=n;i++) {
		if(v[i-1]<i) return no();
		v[i]+=v[i-1]-i;
	}

	cout << "YES\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
