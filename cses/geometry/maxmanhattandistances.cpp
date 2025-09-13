#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
	int n;
	cin >> n;

	set<ll> xy,x,y,sla;
	ll xi,yi,ans=0;

	while(n--) {
		cin >> xi >> yi;

		xy.insert(xi+yi);
		x.insert(xi-yi);
		y.insert(yi-xi);
		sla.insert(-xi-yi);

		ans = max({ans,*xy.rbegin()+*sla.rbegin(),abs(*x.rbegin()+*y.begin())});
		ans = max({ans,*x.rbegin()-*x.begin(),*y.rbegin()-*y.begin()});

		cout << ans << '\n';
	}

	return 0;
}
