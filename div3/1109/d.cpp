#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n,m;
	cin >> n >> m;

	int p[n];
	bool post[n];
	fill(post,post+n,false);
	
	for(int i=0;i<n;i++) cin >> p[i];
	for(int i=0;i<m;i++) {
		int x;
		cin >> x;
		post[x-1] = true;
	}

	ll ans = 0;
	ll act = 0;
	for(int i=0;i<n;i++) {
		act += p[i];

		if(post[i]) {
			ans += max(act,-act);
			act = 0;
		}
	}

	cout << ans+act << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
