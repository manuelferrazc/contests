#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;
const int MAX = 2'000'001;

ll fat[MAX];
ll ifat[MAX];

ll fexp(ll n, ll e) {
	ll r = 1;
	while(e) {
		if(e&1) r = r*n%mod;
		e/=2;
		n = n*n%mod;
	}
	return r;
}

ll comb(ll n, ll k) {
	ll den = ifat[k]*ifat[n-k]%mod;
	return fat[n]*den%mod;
}

void solve() {
	int n;
	string s;
	cin >> n >> s;

	vector<int> v(1,1);
	for(int i=1;i<n;i++) {
		if(s[i]==s[i-1]) v.back()++;
		else v.push_back(1);
	}

	ll ex = 0;
	int n2 = v.size();

	for(int i=0;i<n2;i+=2) ex+=v[i]-1;
	int qtd = (v.size()+1)/2;

	ll ans = comb(ex+qtd-1,ex);

	ex = 0;
	for(int i=1;i<n2;i+=2) ex+=v[i]-1;
	qtd = v.size()/2;
	//cout << ex << ' ' << qtd << '\n';
	if(ex) ans = ans*comb(ex+qtd-1,ex)%mod;

	cout << ans << '\n';
}

int main() { 
	fat[0] = 1;
	for(int i=1;i<MAX;i++) fat[i] = fat[i-1]*i%mod;
	ifat[MAX-1] = fexp(fat[MAX-1],mod-2);
	for(int i=MAX-2;i>=0;i--) ifat[i] = ifat[i+1]*(i+1)%mod;

	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
