#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;

ll fat[200'001];
ll ifat[200'001];

ll fexp(ll n, int e) {
	ll r = 1;
	while(e) {
		if(e&1) r = r*n%mod;
		e>>=1;
		n = n*n % mod;
	}

	return r;
}

ll comb(ll n, ll k) {
	return fat[n]*(ifat[k]*ifat[n-k]%mod)%mod;
}

void solve() {
	int n;
	cin >> n;

		map<int,int> m;
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;
		m[x]++;
	}

	ll qpar = 0;
	ll q1imp = 0;
	for(int i=0;i<=m[-1];i++) {
		if(i&1) q1imp += comb(m[-1],i);
		else qpar += comb(m[-1],i);
	}

	qpar %= mod;
	q1imp %= mod;
	m.erase(-1);
	ll ans = qpar;

	map<int,ll> sufpar;
	sufpar[INT_MAX] = 1;
	for(auto it = m.rbegin();it!=m.rend();it++) {
		int i = it->ff;
		int qtd = it->ss;

		ll &suf = sufpar[i];
		suf = 0;
		for(int k=0;k<=qtd;k+=2) suf+=comb(qtd,k);
		suf%=mod;

		suf *= sufpar.upper_bound(i)->ss;
		suf %= mod;
	}

	ll qmmpar = 1;
	int sla = 1;
	
	ll qmimp = 0;
	// cout << ans << ' ';
	for(auto [val,qtd]:m) { 
		ll nqpar = 0;
		for(;sla<val-1;sla++) {
			auto it = m.lower_bound(sla);
			if(it==m.end()) break;
			if(it->ff>=val-1) break;
			ll qmmmpar = 0;
			for(int i=0;i<=it->ss;i+=2) qmmmpar = (qmmmpar + comb(it->ss,i)) % mod;
			sla = it->ff;
			qmmpar *= qmmmpar;
			qmmpar %= mod;
		}
	
		for(int i=2;i<=qtd;i+=2) nqpar += comb(qtd,i);
		nqpar %= mod;

		ans += nqpar * qpar;
		nqpar = (nqpar + comb(qtd,0)) % mod;
		ans %= mod;
		//cout << ans << ' ';
		ll nqimp = 0;
		
		for(int i=1;i<=qtd;i+=2) nqimp += comb(qtd,i);
		nqimp %= mod;

		if(m.count(val-1)) {
			ans += (((q1imp * qmimp % mod) * nqimp % mod) * qmmpar % mod)*sufpar.upper_bound(val)->ss % mod;
			ans %= mod;
		}

		qmimp = nqimp;
		qpar *= nqpar;
		qpar %= mod;
		// cout << ans << ' ';
	}

	//exit(0);
	cout << ans << '\n';
}

int main() { _
	fat[0] = 1;
	for(int i=1;i<=200'000;i++) fat[i] = fat[i-1]*i%mod;
	ifat[200'000] = fexp(fat[200'000],mod-2);
	for(int i=199'999;i>=0;i--) ifat[i] = ifat[i+1]*(i+1)%mod;

	//for(int i=0;i<=200000;i++) if(ifat[i]*fat[i]%mod != 1) exit(0);

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
