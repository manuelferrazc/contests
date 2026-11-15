#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	
}

int main() { _
	int n;
	cin >> n;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	ll ans = 1;
	int c[n+1];
	fill(c,c+(n+1),0);

	for(int i=0;i<n;i++) {
		if(i==0 or v[i]!=v[i-1]) ans += i-c[v[i]];
		c[v[i]]++;
	}

	cout << ans << '\n';

	return 0;
}
