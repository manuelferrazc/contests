#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	string s;
	cin >> n >> s;

	int f=-1,l=-1,q=0;
	for(int i=0;i<n;i++) {
		if(s[i]=='1') {
			q++;
			if(f==-1) f = i;
			l = i;
		}
	}

	if(q>=3) cout << l-f << '\n';
	else if(q==2) cout << 1 << '\n';
	else cout << 0 << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
