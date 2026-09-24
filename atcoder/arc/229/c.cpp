#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll calc(const ll *v, int n, ll l, ll r) {
	ll ans[n];
	ans[0] = l;
	ans[n-1] = r;

	vector<ll> pa,im;
	for(int i=0;i<n;i++) {
		if(v[i]==l) {
			l=-1;
			continue;
		} else if(v[i]==r) {
			r = -1;
			continue;
		}
		if(v[i]&1ll) im.push_back(v[i]);
		else pa.push_back(v[i]);
	}

	// se tem >=1 par, ans0 eh impar
	if(ans[n-1]&1) swap(ans[0],ans[n-1]);

	for(int i=1;i<n-1;i++) {
		if(ans[i-1]&1) {
			if(pa.size() and pa.back()==l) {
				pa.pop_back();
				l = -1;
			}
			if(pa.size() and pa.back()==r) {
				pa.pop_back();
				r = -1;
			}

			if(pa.size()) {
				ans[i] = pa.back();
				pa.pop_back();
			} else {
				if(im.back()==l) {
					l=-1;
					im.pop_back();
				}
				if(im.back()==r) {
					r = -1;
					im.pop_back();
				}

				ans[i] = im.back();
				im.pop_back();
			}
		} else {
			if(im.size() and im.back()==l) {
				im.pop_back();
				l = -1;
			}
			if(im.size() and im.back()==r) {
				im.pop_back();
				r = -1;
			}

			if(im.size()) {
				ans[i] = im.back();
				im.pop_back();
			} else {
				if(pa.back()==l) {
					pa.pop_back();
					l=-1;
				}
				if(pa.back()==r) {
					pa.pop_back();
					r=-1;
				}

				ans[i] = pa.back();
				pa.pop_back();
			}
		}
	}

	ll ret = 0;
	for(int i=1;i<n;i++) ret += (ans[i-1]+ans[i])/2ll;

	return ret;
}

void solve() {
	int n;
	cin >> n;

	ll v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v,v+n);

	map<ll,ll> mx;
	int i = n-1;
	while(i>=0 and mx.size()<=4) {
		if(not mx.count(v[i])) mx[v[i]] = 1;
		else if(mx[v[i]]==1) mx[v[i]] = 2;
		i--;
	}

	vector<ll> v2;
	for(auto [val,qtd]:mx) {
		while(qtd--) v2.push_back(val);
	}

	sort(v2.begin(),v2.end());

	ll ans = LLONG_MAX;
	for(i=0;i<(int)v2.size();i++)
		for(int j=i+1;j<(int)v2.size();j++)
			ans = min(ans,calc(v,n,v2[i],v2[j]));

	cout << ans << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
