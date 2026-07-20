#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll n,c;
	cin >> n >> c;

	int v[n];
	for(int i=0;i<n;i++) cin >> i[v];

	sort(v,v+n);
	ll ans = 0;
	for(int i=0;i<(n+1)/2;i++) ans+= v[n-i-1]-c;

	for(int i = (n+1)/2;i<n;i++) {
		if(v[n-i-1]>c) ans+= v[n-i-1]-c;
		else break;
	}
	
	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
