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
	int n,x,y;
	cin >> n >> x >> y;

	int g = gcd(x,y);
	int v[n+1];
	for(int i=1;i<=n;i++) cin >> i[v];

	for(int i=1;i<=g;i++) {
		set<int> req;
		for(int j=i;j<=n;j+=g) req.insert(v[j]);

		for(int j=i;j<=n;j+=g) {
			set<int>::iterator it = req.find(j);
			if(it==req.end()) return no();
			req.erase(it);
		}
	}

	cout << "YES\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
