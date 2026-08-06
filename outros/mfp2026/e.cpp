#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;


int main() { _
	int a,b,c;
	cin >> a >> b >> c;

	int ans = gcd(b-a,c-b);

	pair<int,int> p[] = {pair(a,1),pair(b,2),pair(c,3)};
	sort(p,p+3);
	vector<pair<int,int>> ans2;

	while(p[1].ff-p[0].ff!=p[2].ff-p[1].ff) {
		int d1 = p[1].ff-p[0].ff;
		int d2 = p[2].ff-p[1].ff;

		if(d1<d2) {
			int x = p[0].ff;
			int y = p[1].ff;

			p[0].ff = 2*y-x;
			ans2.push_back(pair(p[0].ss,p[1].ss));
		} else {
			int x = p[2].ff;
			int y = p[1].ff;
			p[2].ff = 2*y-x;
			ans2.push_back(pair(p[2].ss,p[1].ss));
		}
		sort(p,p+3);
	}

	cout << ans << ' ' << ans2.size() << '\n';
	for(auto [aa,bb]:ans2) cout << aa << ' ' << bb << '\n';

	return 0;
}
