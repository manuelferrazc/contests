#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second
#define _ ios_base::sync_with_stdio();cin.tie(0);
typedef long long ll;
typedef unsigned long long ull;

template<typename T> vector<int> pi(T s) {
	vector<int> p(s.size());
	for(int i=1,j=0;i<s.size();i++) {
		while(j and s[j]!=s[i]) j = p[j-1];
		if(s[j]==s[i]) j++;
		p[i] = j;
	}
	return p;
}

template<typename T> vector<int> matching(T &s, T &t) {
	vector<int> p = pi(s), match;
	for(int i=0,j=0;i<t.size();i++) {
		while(j and s[j]!=t[i]) j = p[j-1];
		if(s[j]==t[i]) j++;
		if(j==s.size()) match.push_back(i-j+1), j = p[j-1];
	}
	return match;
}

int main() { _
	string s,t;
	cin >> s >> t;
	ll n = s.size();
	ll m = t.size();

	vector<ll> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	while(s.size()<t.size()) {
		s += s;
		for(int i=0;i<n;i++) v.push_back(v[i]);
		n <<= 1;
	}

	s+=s;
	vector<int> mt = matching(t,s);

	pair<int,ll> pot[n];
	for(int i=0;i<n;i++) {
		auto it = lower_bound(mt.begin(),mt.end(),i);
		if(it==mt.end() or *it!=i) pot[i] = pair(-1,-1ll);
		else pot[i] = pair(0,v[i]);
	}

	for(int j=1;j<24;j++) {
		pair<int,ll> np[n];
		for(ll i=0;i<n;i++) {
			if(min(pot[i].ff, pot[(i+(m<<(j-1)))%n].ff)==j-1) {
				np[i].ff = j;
				np[i].ss = pot[i].ss + pot[(i+(m<<(j-1)))%n].ss;
			} else np[i] = pot[i];
		}
		for(int i=0;i<n;i++) pot[i] = np[i];
	}

	for(int i=0;i<n;i++) {
		if(pot[i].ff>21) {
			cout << -1 << '\n';
			return 0;
		}
	}

	ll ans = 0;
	vector<ll> acc(n,0);

	for(int j=23;j>=0;j--) {
		for(int i=0;i<n;i++) {
			if(pot[i].ff==j) {
				ans = max(ans,pot[i].ss+acc[i]);
				if(j>0) {
					ll ni = (i+(m<<j))%n;
					if(pot[ni].ff!=-1) acc[ni] = max(acc[ni],pot[i].ss+acc[i]);
				}
			}
		}
	}

	cout << ans << '\n';

	return 0;
}
