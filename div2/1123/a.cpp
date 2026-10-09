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

	string s,c2;
	cin >> c2 >> s;

	char c = c2[0];

	int ans=0;

	for(int i=0,j=n-1;i<j;i++,j--) {
		if(s[i]==s[j]) continue;

		ans+=2;

		if(s[i]==c or s[j]==c) ans--;
	}
	
	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
