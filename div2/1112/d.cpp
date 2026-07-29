#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 998244353;

ll solve() {
	int n;
	cin >> n;

	int v[n-1];
	for(int i=0;i<n-1;i++) cin >> v[i];
	vector<pair<int,int>> f(n+1,pair(-1,-1));
	for(int i=0;i<n-1;i++) {
		if(f[v[i]].ff==-1) {
			f[v[i]].ff = i;
			f[v[i]].ss = i;
			while(i<n-2 and v[i]==v[i+1]) {
				i++;
				f[v[i]].ss++;
			}
		} else return 0;
	}

	if(f[n].ff!=-1 or f[n-1].ff==-1) return 0;

	for(int i=f[n-1].ff-1;i>=0;i--) if(v[i]>v[i+1]) return 0;
	for(int i=f[n-1].ss+1;i<n-1;i++) if(v[i]>v[i-1]) return 0;

	ll ans = 2;
	ll qtd = 0;
	ll pref = v[0];
	ll suf = v[n-2];
	//cout << "TESTCASE\n";
	while(min(pref,suf)<n-1) {
		qtd++;
		ll av = min(pref,suf) - qtd;

		ll x = min(pref,suf);
		//cout << "x = " << x << ':';
		ll m=0;
		for(int i=f[x].ff+1;i<=f[x].ss;i++) {
			if(av==0) return 0;
			m++;
			ans*=av;
			//cout << av << ',';
			ans %= mod;
			qtd++;
			av--;
		}

		//cout << " --- total = " << m << '\n';

		if(pref==x) pref = v[f[x].ss+1];
		else suf = v[f[x].ff-1];
	}

	//av += n-1-qtd;
	qtd+=2;
	while(qtd<n) {
		ans *= (n-qtd);
		ans %= mod;
		qtd++;
	}

	return ans;
}

int main() { _
	int t;
	cin >> t;
	while(t--) cout << solve() << '\n';
	return 0;
}
