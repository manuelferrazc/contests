#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) {
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

ll fexp(ll n, ll e, ll m) {
	if(e==0) return 1;
	if(e==1) return n;

	ll r = fexp(n,e>>1,m);
	r = r*r%m;
	if(e&1) r = r*n%m;

	return r;
}

struct hhash {
	ll b,mod;
	vector<ll> p,h;

	hhash(const string &s, ll m, ll _b) {
		p.resize(s.size());
		h.resize(s.size());
		mod = m;
		b = _b;

		p[0] = 1;
		h[0] = s[0];

		for(int i=1;i<(int)s.size();i++) {
			p[i] = p[i-1]*b%mod;
			h[i] = (h[i-1]*b+s[i])%mod;
		}
	}

	ll get(int l, int r) {
		if(l==0) return h[r];
		return (h[r]-(h[l-1]*p[r-l+1]%mod)+mod)%mod;
	}
};

int main() { _
    string s,r;
    cin >> s;
	int n = s.size();
    r = s;
    reverse(r.begin(),r.end());    
    
	ll b = uniform(26,500);
	ll b2 = uniform(26,500);
	hhash s1(s,1'000'000'033,b),s2(s,1'000'000'087,b2);
	hhash r1(r,1'000'000'033,b),r2(r,1'000'000'087,b2);

	
	for(int i=n-1;i>=0;i--) {
		if(s1.get(n-1-i,n-1)==r1.get(0,i) and s2.get(n-1-i,n-1)==r2.get(0,i)) {
			cout << s+r.substr(i+1) << '\n';
			return 0;
		}
	}
    return 0;
}
