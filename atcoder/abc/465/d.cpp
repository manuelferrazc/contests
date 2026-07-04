#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	ll x,y,k;
	cin >> x >> y >> k;

	map<pair<ll,ll>,int> yy;
	for(ll l=y,r=y;;) {
		yy[pair(l,r)] = yy.size();
		//cout << l << ' ' << r << '\n';
		if(l==0ll) break;
		l/=k;
		r/=k;
	}

	int ans = INT_MAX;
	int qtd=0;
	for(ll i=x;;i/=k) {
		for(auto it = yy.begin();it!=yy.end();it++) {
			if(it->ff.ff>i) break;
			if(i<=it->ff.ss) ans = min(ans,qtd+it->ss);
		}

		if(i==0ll) break;
		qtd++;
	}

	cout << ans << '\n';
}

int main() { 
	int t;
	cin >> t;
	while(t--) solve();

    return 0;
}
