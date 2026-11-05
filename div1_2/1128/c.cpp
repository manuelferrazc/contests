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

	ll sum = 0;
	int qi = 0;

	for(int i=0;i<n;i++) {
		int x;
		cin >> x;

		sum += x;
		if(x&1) qi++;
	}

	if(sum%2==0 or n==1) cout << "Moggity\n";
	else if(n==2) cout << "Larpity\n";
	else if(qi>3 /* mando iii */ or qi!=n) cout << "Moggity\n";
	else cout << "Larpity\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
