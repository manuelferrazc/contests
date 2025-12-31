#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct pt { // ponto
	ll x, y;
	pt(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ll c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}

// RETA

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return (a ^ b) == 0 and (a * b) <= 0;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if ((a.p.x!=a.q.x) and ((b.p.x==b.q.x) or a.p.x < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool simple(vector<pt> v) {
	auto intersects = [&](pair<line, ll> a, pair<line, ll> b) {
		if ((a.second+1)%v.size() == b.second or
			(b.second+1)%v.size() == a.second) return false;
		return interseg(a.first, b.first);
	};
	vector<line> seg;
	vector<pair<pt, pair<ll, ll>>> w;
	for (ll i = 0; i < v.size(); i++) {
		pt at = v[i], nxt = v[(i+1)%v.size()];
		if (nxt < at) swap(at, nxt);
		if(i<v.size()-1) {
			seg.push_back(line(at, nxt));
			w.push_back({at, {0, i}});
			w.push_back({nxt, {1, i}});
		}
		// casos degenerados estranhos
		if (isinseg(v[(i+2)%v.size()], line(at, nxt))) return 0;
		if (isinseg(v[(i+v.size()-1)%v.size()], line(at, nxt))) return 0;
	}
	sort(w.begin(), w.end());
	set<pair<line, ll>> se;
	for (auto i : w) {
		line at = seg[i.second.second];
		if (i.second.first == 0) {
			auto nxt = se.lower_bound({at, i.second.second});
			if (nxt != se.end() and intersects(*nxt, {at, i.second.second})) return 0;
			if (nxt != se.begin() and intersects(*(--nxt), {at, i.second.second})) return 0;
			se.insert({at, i.second.second});
		} else {
			auto nxt = se.upper_bound({at, i.second.second}), cur = nxt, prev = --cur;
			if (nxt != se.end() and prev != se.begin()
				and intersects(*nxt, *(--prev))) return 0;
			se.erase(cur);
		}
	}
	return 1;
}

int main() { _
	int n;
	cin >> n;

	ll s=0;
	pair<char,int> v[n];

	for(int i=0;i<n;i++) {
		string st;
		cin >> st >> v[i].ss;
		v[i].ff = st[0];
		s+=v[i].ss;
	}

	ll ans = s;
	ll l=v[0].ss,r=ans-1;

	while(l<=r) {
		ll m = (l+r)>>1;

		ll act = m;
		vector<pt> pol;
		pt p(0,0);
		pol.push_back(p);

		bool err = false;

		for(int i=0;i<n;i++) {
			if(i) {
				if(v[i].ff=='U' and v[i-1].ff=='D') err = true;
				else if(v[i].ff=='D' and v[i-1].ff=='U') err = true;
				else if(v[i].ff=='L' and v[i-1].ff=='R') err = true;
				else if(v[i].ff=='R' and v[i-1].ff=='L') err = true;
				if(err) break;
			}
			int qtd;
			if(v[i].ss<act) {
				act-=v[i].ss;
				qtd = v[i].ss;
			} else {
				qtd = act;
				act = 0;
			}

			if(v[i].ff=='U') p.y+=qtd;
			else if(v[i].ff=='D') p.y-=qtd;
			else if(v[i].ff=='R') p.x+=qtd;
			else p.x-=qtd;

			pol.push_back(p);
			if(act==0) break;
		}

		if(err or not simple(pol)) {
			ans = m+1;
			l=m+1;
		} else r=m-1;
	}

	cout << ans << '\n';

	return 0;
}
