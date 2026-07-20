#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long lll;
typedef unsigned long long ull;

pair<lll,lll> read() {
	lll x,y;
	cin >> x >> y;
	return pair(x,y);
}

const char * yes = "Yes\n";
const char * no  = "No\n";

typedef __int128 ll;

const char * solve() {
	pair<lll,lll> p = read(), q = read();	
	pair<lll,lll> r = read(), s = read();

	// ax + by = k
	// cx + dy = l

	ll a = 2*(q.x-p.x);
	ll b = 2*(q.y-p.y);

	ll c = 2*(r.x-s.x);
	ll d = 2*(r.y-s.y);

	ll det = a*d - b*c;
	if(det) return yes;

	ll l = q.x*q.x + q.y*q.y - p.x*p.x - p.y*p.y;
	ll k = r.x*r.x + r.y*r.y - s.x*s.x - s.y*s.y;

	// no max 1 entre a e b e 0; msm vale pra c e d
	
	if(a==0 or c==0) {
		// faz x=0
		// l/b == k/d -> l*d == k*b
		if(k*b==l*d) return yes;
		return no;
	} else {
		// av em y=0
		// x = l/a && x = k/c -> l/a==k/c
		if(l*c==k*a) return yes;
		return no;
	}
}

int main() { _
	int t;
	cin >> t;

	while(t--) cout << solve();

    return 0;
}
