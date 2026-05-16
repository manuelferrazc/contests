#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	string s;
	cin >> s;

	int n = s.size();
	ll ans = 0;

	for(int i=0;i<n;i++) {
		if(s[i]!='C') continue;

		int left = i;
		int right = n-i-1;

		ans += 1+min(left,right);
	}

	cout << ans << '\n';

	return 0;
}
