#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	string s;
	cin >> s;
	int n = s.size();

	int k1=-1;
	for(int i=0;i<n;i++) if(s[i]=='0') {
		k1 = i;
		break;
	}

	int k2 = -1;
	for(int i=0;i<n;i++) if(s[i]=='1') {
		k2 = i;
		break;
	}

	for(int i=0;i<n;i++) {
		if(i!=k1 and i!=k2) cout << s[i];
	}
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
