#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

ll fexp(ll n, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = r*n%mod;
		e>>=1;
		n = n*n%mod;
	}
	return r;
}

bool comp(pair<ll,ll> a, pair<ll,ll> b) {
	// a = a1/a2, b = b1/b2
	// a<b -> a1/a2 < b1/b2 -> a1b2 < b1a2

	return a.ff*b.ss < a.ss*b.ff;
}

void solve() {
	int n;
	cin >> n;

	ll a[n];
	ll b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	ll ans = 0;
	
	vector<pair<ll,ll>> va;
	for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) va.push_back(pair(a[i],a[j]));

	vector<pair<ll,ll>> vb;
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) if(i!=j) vb.push_back(pair(b[i],b[j]));

	sort(va.begin(),va.end(),comp);
	sort(vb.begin(),vb.end(),comp);
	
	int bi=0;
	for(int i=0;i<(int)va.size();i++) {
		while(bi<(int)vb.size() and comp(vb[bi],va[i])) bi++;
		ans+=bi;
		ans%=mod;
	}

	cout << ans*fexp(n*(n-1),mod-2)%mod << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
