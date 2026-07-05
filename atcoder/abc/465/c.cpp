#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n;
	string s;

	cin >> n >> s;

	deque<int> ans;
	bool inv = false;

	for(int i=0;i<n;i++) {
		if(s[i]=='o') {
			if(inv) ans.push_front(i+1);
			else ans.push_back(i+1);
			inv = not inv;
		} else {
			if(inv) ans.push_front(i+1);
			else ans.push_back(i+1);
		}
	}

	int step = inv ? -1 : 1;
	for(int i= inv ? n-1 : 0 ; i!=-1 and i!=n ;i+=step) cout << ans[i] << ' ';
	cout << '\n';

    return 0;
}
