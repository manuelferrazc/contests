#include <bits/stdc++.h>

// Otimizacoes agressivas, pode deixar mais rapido ou mais devagar
#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
// Vetorizacao
#pragma GCC target("avx2")
// Para operacoes com bits
#pragma GCC target("bmi,bmi2,popcnt,lzcnt")

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

struct St {
	int n;
	vector<int> bit;

	St(int _n): n(_n), bit(n+1) {}

	void update(int i) {
		for(i++;i<=n;i+= i & -i) bit[i]++;
	}

	int pref(int i) {
		int ret = 0;
		for(i++;i;i-= i & -i) ret += bit[i];
		return ret;
	}
	
	int get(int l, int r) {
		return pref(r)-pref(l-1);
	}

};

void solve() {
	int n;
	cin >> n;

	ll a[n];
	ll b[n];
	for(int i=0;i<n;i++) cin >> a[i];
	for(int i=0;i<n;i++) cin >> b[i];

	vector<ll> v;
	v.push_back(0);
	for(ll i:a) for(ll j:b) v.push_back(i*j);
	
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());

	St s(v.size()+1);

	vector<St*> stb(n);
	for(int i=0;i<n;i++) stb[i] = new St(n+1);

	vector<ll> vb[n];
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) vb[i].push_back(b[i]*a[j]);
	for(int i=0;i<n;i++) {
		vb[i].push_back(0);
		sort(vb[i].begin(),vb[i].end());
		vb[i].erase(unique(vb[i].begin(),vb[i].end()),vb[i].end());
	}

	ll ans = 0;
	ll inv = fexp(n*(n-1),mod-2);

	for(int i=n-1;i>=0;i--) {
		for(int j=0;j<n;j++) {
			ll val = a[i]*b[j];
			
			int id = lower_bound(v.begin(),v.end(),val)-v.begin();
			ans += s.get(0,id-1);
			
			id = lower_bound(vb[j].begin(),vb[j].end(),val)-vb[j].begin();
			ans -= stb[j]->get(0,id-1);

			ans%=mod;
		}

		for(int j=0;j<n;j++) {
			int id = lower_bound(vb[j].begin(),vb[j].end(),a[i]*b[j])-vb[j].begin();
			stb[j]->update(id);
		}
		for(int j=0;j<n;j++) {
			int id = lower_bound(v.begin(),v.end(),a[i]*b[j])-v.begin();
			s.update(id);
		}
	}

	for(int i=0;i<n;i++) delete stb[i];

	cout << ans*inv%mod << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
