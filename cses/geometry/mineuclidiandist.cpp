#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll dist2(pt p, pt q) { // quadrado da distancia
	return sq(p.x - q.x) + sq(p.y - q.y);
}

pair<pt, pt> closest_pair_of_points(vector<pt> v) {
	int n = v.size();
	sort(v.begin(), v.end());
	for (int i = 1; i < n; i++) if (v[i] == v[i-1]) return {v[i-1], v[i]};
	auto cmp_y = [&](const pt &l, const pt &r) {
		if (l.y != r.y) return l.y < r.y;
		return l.x < r.x;
	};
	set<pt, decltype(cmp_y)> s(cmp_y);
	int l = 0, r = -1;
	ll d2_min = numeric_limits<ll>::max();
	pt pl, pr;
	const int magic = 5;
	while (r+1 < n) {
		auto it = s.insert(v[++r]).first;
		int cnt = magic/2;
		while (cnt-- and it != s.begin()) it--;
		cnt = 0;
		while (cnt++ < magic and it != s.end()) {
			if (!((*it) == v[r])) {
				ll d2 = dist2(*it, v[r]);
				if (d2_min > d2) {
					d2_min = d2;
					pl = *it;
					pr = v[r];
				}
			}
			it++;
		}
		while (l < r and sq(v[l].x-v[r].x) > d2_min) s.erase(v[l++]);
	}
	return {pl, pr};
}

int main() { _
	int n;
	cin >> n;
	vector<pt> v(n);
	for(int i=0;i<n;i++) cin >> v[i];

	auto p = closest_pair_of_points(v);
	ll dx = p.ff.x-p.ss.x, dy = p.ff.y-p.ss.y;
	cout << dx*dx+dy*dy << '\n';

	return 0;
}
