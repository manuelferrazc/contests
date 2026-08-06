#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "-1\n";
}

void solve() {
	int n;
	cin >> n;

	ll b[n];
	map<ll,vector<ll>> m;
	for(int i=0;i<n;i++ ) {
		cin >> b[i];
		m[b[i]].push_back(i);
	}

	ll a[n];
	if(m.begin()->ff!=0) return no();
	ll s=0;
	//if(m.size()==1) for(auto i:m[0]) a[i] = 1, s++;
	//else {
	//	ll nx = m.upper_bound(0)->ff;
	//	if(nx%m[0].size()) retu

	ll last = 0;
	for(auto it = m.begin();it!=m.end();it++) {
		auto it2 = next(it);

		ll nx;
		if(it2==m.end()) nx = last+1;
		else {
			ll dif = it2->ff - s;
			if(dif<0 or dif%(it->ss.size())) return no();
			nx = dif/(it->ss.size());
			if(nx<=last) return no();
		}
		
		for(ll i:it->ss) a[i] = nx, s+=nx;
		last = nx;
	}

	for(int i=0;i<n;i++) cout << a[i] << ' ';
	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
