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
	if(r.p.x==r.q.x) 
		return p.x==r.p.x and min(r.p.y,r.q.y)<=p.y and p.y<=max(r.p.y,r.q.y);
	else 
		return p.y==r.p.y and min(r.p.x,r.q.x)<=p.x and p.x<=max(r.p.x,r.q.x);
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}

bool operator < (const line& a, const line& b) { // comparador pro sweepline
	if (a.p == b.p) return ccw(a.p, a.q, b.q);
	if (a.p.x!=a.q.x and (b.p.x == b.q.x or a.p.x < b.p.x))
		return ccw(a.p, a.q, b.p);
	return ccw(a.p, b.q, b.p);
}

bool has_intersection(vector<line> &v) {
	auto intersects = [&](pair<line, int> a, pair<line, int> b) {
		if(abs(a.ss-b.ss)==1) return false;
		return interseg(a.first, b.first);
	};
	vector<pair<pt, pair<int, int>>> w;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].q < v[i].p) swap(v[i].p, v[i].q);
		w.push_back({v[i].p, {0, i}});
		w.push_back({v[i].q, {1, i}});
	}
	sort(w.begin(), w.end());
	set<pair<line, int>> se;
	for (auto i : w) {
		line at = v[i.second.second];
		if (i.second.first == 0) {
			auto nxt = se.lower_bound({at, i.second.second});
			if (nxt != se.end() and intersects(*nxt, {at, i.second.second})) return 1;
			if (nxt != se.begin() and intersects(*(--nxt), {at, i.second.second})) return 1;
			se.insert({at, i.second.second});
		} else {
			auto nxt = se.upper_bound({at, i.second.second}), cur = nxt, prev = --cur;
			if (nxt != se.end() and prev != se.begin()
				and intersects(*nxt, *(--prev))) return 1;
			se.erase(cur);
		}
	}
	return 0;
}

int compress(vector<line> &v) {
	set<int> s;
	for(int i=0;i<(int)v.size();i++) {
		s.insert(v[i].p.x);
		s.insert(v[i].p.y);
		s.insert(v[i].q.x);
		s.insert(v[i].q.y);
	}

	map<int,int> m;
	int val = 0;
	for(auto i:s) m[i] = val++;

	for(int i=0;i<(int)v.size();i++) {
		v[i].p.x = m[v[i].p.x];
		v[i].p.y = m[v[i].p.y];
		v[i].q.x = m[v[i].q.x];
		v[i].q.y = m[v[i].q.y];
	}

	return val;
}

inline bool vert(line &l) {
	return l.q.x==l.p.x;
}

int find_err(vector<line> v) {
	int r = v.size();

	int mx = compress(v);
	
	vector<array<int,3>> ev;	for(int i=0;i<n;i++) {
		if(vert(v[i])) ev.push_back({v[i].p.x,2,i});
		else {
			ev.push_back({min(v[i].p.x,v[i].q.x),1,i});
			ev.push_back({max(v[i].p.x,v[i].q.x),3,i})
		}
	}
	
	sort(ev.begin(),ev.end());
	
	set<int> leaves[mx];

	array<int,4> st[4*mx];
	for(int i=0;i<4*mx;i++) st[i][0] = st[i][1] = st[i][2] = st[i][3] = -1;

	

	
	return r;
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
		bool err = false;
		if(i) {
			if(v[i].ff=='U' and v[i-1].ff=='D') err = true;
			else if(v[i].ff=='D' and v[i-1].ff=='U') err = true;
			else if(v[i].ff=='L' and v[i-1].ff=='R') err = true;
			else if(v[i].ff=='R' and v[i-1].ff=='L') err = true;
			if(err) {
				n = i;
				break;
			}			
		}
	}

	int steps=1;
	pt last;

	{int l=1,r=n;


	while(l<=r) {
		int m = (l+r)>>1;

		vector<line> ln;
		pt p(0,0);

		bool err = false;

		for(int i=0;i<m;i++) {
			if(i) {
				if(v[i].ff=='U' and v[i-1].ff=='D') err = true;
				else if(v[i].ff=='D' and v[i-1].ff=='U') err = true;
				else if(v[i].ff=='L' and v[i-1].ff=='R') err = true;
				else if(v[i].ff=='R' and v[i-1].ff=='L') err = true;
				if(err) break;
			}
			
			pt pa = p;

			if(v[i].ff=='U') p.y+=v[i].ss;
			else if(v[i].ff=='D') p.y-=v[i].ss;
			else if(v[i].ff=='R') p.x+=v[i].ss;
			else p.x-=v[i].ss;

			ln.push_back(line(pa,p));
		}

		pt bk = ln.back().q;

		if(err or has_intersection(ln)) r = m-1;
		else {
			l = m+1;
			steps = m;
			last = bk;
		}
	}}


	if(steps==n) cout << s << '\n';
	else if((v[steps].ff=='U' and v[steps-1].ff=='D')
		or (v[steps].ff=='D' and v[steps-1].ff=='U')
		or (v[steps].ff=='L' and v[steps-1].ff=='R')
		or (v[steps].ff=='R' and v[steps-1].ff=='L')
	) {
		s = 0;
		for(int i=0;i<steps;i++) s+=v[i].ss;
		cout << s << '\n';
	}
	else {
		s = 0;
		for(int i=0;i<steps;i++) s+=v[i].ss;
		bool vert = v[steps].ff=='U' or v[steps].ff=='D';
		
		line err(last,last);
		
		if(v[steps].ff=='U') err.q.y+=v[steps].ss;
		else if(v[steps].ff=='D') err.q.y-=v[steps].ss;
		else if(v[steps].ff=='R') err.q.x+=v[steps].ss;
		else err.q.x-=v[steps].ss;
		
		pt last2 = err.q;

		if(err.p.x>err.q.x or err.p.y>err.q.y) swap(err.p,err.q);
		
		pt act;

		ll d = 1e6;

		for(int i=0;i<steps-1;i++) {
			bool vert2 = false;
			pt bef = act;

			if(v[i].ff=='U') {
				act.y+=v[i].ss;
				vert2 = true;
			}
			else if(v[i].ff=='D') {
				act.y-=v[i].ss;
				vert2 = true;
			}
			else if(v[i].ff=='R') act.x+=v[i].ss;
			else act.x-=v[i].ss;

			line l(act,bef);
			if(l.p.x>l.q.x or l.p.y>l.q.y) swap(l.p,l.q);

			// println("i = {}, pontos = ({},{}), ({},{})",i,bef.x,bef.y,act.x,act.y);
			// println("dps de ordenar: ({},{}), ({},{})",l.p.x,l.p.y,l.q.x,l.q.y);
			if(vert == vert2) {
				ll a1,a2,b1,b2;

				if(err.q.x==err.p.x) {
					if(err.q.x!=l.p.x) continue;
					a1 = l.p.y,a2 = l.q.y;
					b1 = last.y, b2 = last2.y;
				} else {
					if(err.q.y!=l.p.y) continue;
					a1 = l.p.x, a2 = l.q.x;
					b1 = last.x, b2 =last2.x;
				}

				if(a1<=b1 and b1<=a2) {
					d = 0;
					break;
				} else if(a1<=b2 and b2<=a2) {
					if(b1<a1) d = min(d,a1-b1);
					else d = min(d,a2-b1);
				} else if(min(b1,b2)<=a1 and max(b1,b2)>=a2) {
					d = min(d,min(abs(a1-b1),abs(a2-b1)));
				}
			} else if(vert) {
				if(l.p.x<=last.x and last.x<=l.q.x and err.p.y<=l.p.y and l.p.y<=err.q.y) {
					d = min(d,abs(last.y-l.p.y));
				}
			} else if(vert2) {
				if(err.p.x<=l.p.x and l.p.x<=err.q.x and l.p.y<=err.p.y and err.p.y<=l.q.y) {
					d = min(d,abs(last.x-l.p.x));
				}
			}

			// cout << last.x << ' ' << last.y << '\n';
			// cout << last2.x << ' ' << last2.y << '\n';
		}
		
		
		cout << s+d << '\n';
	}
	

	return 0;
}
