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
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	int ans = 1;
	int b=0;
	int n2 = v.size();
	
	for(int a=0;a<n2;a++) {
		while(b<n2 and v[b]-v[a]<n) b++;
		ans = max(ans,b-a);
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
