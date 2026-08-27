#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
	int n,q;
	cin >> n >> q;

	string s;
	cin >> s;

	while(q--) {
		int op;
		cin >> op;

		if(op==1) {
			ll l, r;
			cin >> l >> r;
			l--;
			r--;
			string s2 = s;
			s.clear();
			for(ll i=0;i<s2.size();i++) {
				s.push_back(s2[i]);
				if(l<=i and i<=r) s.push_back(s2[i]);
			}
			//cout << s << '\n';
		} else {
			ll x;
			cin >> x;
			cout << s[x-1] << '\n';
		}
	}

	exit(0);
}
