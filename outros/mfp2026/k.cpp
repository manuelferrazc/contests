#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	string s;
	int k;
	cin >> s >> k;

	string ans;
	for(char c:s) {
		if(c=='#') {
			if(ans.size()) ans.pop_back();
		} else ans.push_back(c);
	}

	if(ans.size()>=k) cout << ans[k-1] << '\n';
	else cout << "-1\n";

	return 0;
}
