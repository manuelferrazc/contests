#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void say(bool ok) {
	if(ok) cout << "YES\n";
	else cout << "NO\n";
}

void solve() {
	int n;
	cin >> n;

	int v[n];
	for(int i=0;i<n;i++) cin >> i[v];

	int mx = 0,k=0;
	for(int i=0;i<n;i++) {
		k = max(k,mx-v[i]);
		mx = max(mx,v[i]);
	}

	for(int i=1;i<n;i++) if(v[i]<v[i-1]) v[i]+=k;

	for(int i=1;i<n;i++) if(v[i]<v[i-1]) return say(false);
	say(true);
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
