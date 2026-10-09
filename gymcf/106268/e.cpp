#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'

using ll = long long int;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

pair <ll,ll> bb(ll a, ll b, ll c, ll k) {
	pair<ll,ll> ret(a,LINF);

	ll l=1,r=k;
	while(l<=r) {
		ll m = (l+r)/2;
		ll qb = b*m/a;
		ll qc = c*m/a;

		if(min({m,qb,qc})>0 and (m>=k or qb>=k or qc>=k or m*qb>=k or m*qb*qc>=k)) {
			ret = pair(a,m);
			r = m-1;
		} else l = m+1;
	}

	return ret;
}

void solve() {	
	ll a,b,c,k;
	cin >> a >> b >> c >> k;

	pair<ll,ll> ans1 = bb(a,b,c,k);
	pair<ll,ll> ans2 = bb(b,a,c,k);
	pair<ll,ll> ans3 = bb(c,a,b,k);
	//cout << ans1.first << ' ' << ans1.second << '\n';
	//cout << ans2.first << ' ' << ans2.second << '\n';
	//cout << ans3.first << ' ' << ans3.second << '\n';
	vector<pair<ll,ll>> ans;
	if(ans1.second!=LINF) ans.push_back(ans1);
	if(ans2.second!=LINF) ans.push_back(ans2);
	if(ans3.second!=LINF) ans.push_back(ans3);

	sort(ans.begin(),ans.end(),[] (pair<ll,ll> aa, pair<ll,ll> bb) -> bool {
		__int128 left = aa.first;
		left*=bb.second;

		__int128 sec = aa.second;
		sec*=bb.first;
		return left>sec;
	});

	auto [p,q] = ans.front();

	ll g = gcd(p,q);
	p/=g;
	q/=g;

	cout << p << ' ' << q << '\n';
}

signed main(){_
	int t;
	cin >> t;

	while(t--) solve();

	return 0;
}


