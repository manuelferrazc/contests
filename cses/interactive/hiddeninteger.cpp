#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() {
	int l = 1, r = 1'000'000'000, ans=INT_MAX;

	while(l<=r) {
		int m = (l+r)>>1;

		cout << "? " << m << '\n';
		cout.flush();
		string s;
		cin >> s;
		if(s[0]=='N') {
			ans = m;
			r=m-1;
		} else l=m+1;
	}

	cout << "! " << ans << '\n';

	return 0;
}
