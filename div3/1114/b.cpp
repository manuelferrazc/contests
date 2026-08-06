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

	int l=1;
	string s2;
	//s2.push_back(s.front();
	for(int i=1;i<n;i++) {
		if(s[i]!=s[i-1]) l++, s2.push_back(s[i]);
	}

	//cout << l << ' ';

	int ok = 0;
	for(int i=1;i<n-1;i++) {
		if(s[i]!=s[i-1] and s[i-1]==s[i+1]) {
			cout << l-2 << '\n';
			return;
		}

		if(s[i]!=s[i-1] and s[i]!=s[i+1]) ok = 1;
	}

	cout << l-ok << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
