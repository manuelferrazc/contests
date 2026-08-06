#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int n,ans=0;
	cin >> n;

	while(n--) {
		string s;
		int x;
		cin >> s >> x;
		if(s[0]=='-') ans-=x;
		else ans+=x;
	}

	cout << ans << '\n';

	return 0;
}
