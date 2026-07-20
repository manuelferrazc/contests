#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;

	if(k>n/2) return -1;

	int ans = 0;
	for(int i=0;i<k;i++) {
		if(s[i]=='L') ans++;
		s[i] = 'R';
	}

	for(int i=0;i<k;i++) {
		if(s[n-i-1]=='R') ans++;
		s[n-i-1] = 'L';
	}

	return ans;
}

int main() { _
	int t;
	cin >> t;
	while(t--) cout << solve() << '\n';
	return 0;
}
