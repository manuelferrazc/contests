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

	int z=0,u=0;

	for(int i=0;i<n;i+=2) {
		if(a[i]=='0') z++;
		else u++;

		if(b[i]=='0') z--;
		else u--;
	}

	if(u or z) {
		cout << "-1\n";
		return;
	}

	for(int i=1;i<n;i+=2) {
		if(a[i]=='0') z++;
		else u++;

		if(b[i]=='0') z--;
		else u--;
	}

	if(u or z) {
		cout << "-1\n";
		return;
	}
	
	int nx = 2;
	ll ans = 0;
	for(int i=0;i<n;i+=2) {
		nx = max(nx,i+2);
		if(a[i]!=b[i]) {
			while(a[nx]==a[i]) nx+=2;
			ans += (nx-i)/2;
			a[nx] = a[i];
		}
	}

	nx = 3;
	for(int i=1;i<n;i+=2) {
		nx = max(nx,i+2);
		if(a[i]!=b[i]) {
			while(a[nx]==a[i]) nx+=2;
			ans += (nx-i)/2;
			a[nx] = a[i];
		}
	}

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
