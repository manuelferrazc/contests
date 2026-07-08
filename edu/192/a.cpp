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

	sort(v,v+n);
	if(v[n-1]>2 or (n>1 and v[n-2]>1)) cout << "YES\n";
	else cout << "NO\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
