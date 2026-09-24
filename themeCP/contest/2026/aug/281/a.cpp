#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	string a,b;
	cin >> n >> a >> b;

	int ans=0;
	for(int i=1;i<n-1;i++) {
		if(a[i-1]=='.' and a[i]=='.' and a[i+1]=='.' and b[i]=='.' and b[i-1]=='x' and b[i+1]=='x') ans++;

		swap(a,b);
		if(a[i-1]=='.' and a[i]=='.' and a[i+1]=='.' and b[i]=='.' and b[i-1]=='x' and b[i+1]=='x') ans++;
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
