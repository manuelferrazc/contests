#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

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
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea2(p, q, r) > 0;
}


typedef struct QuadEdge* Q;
struct QuadEdge {
	int id;
	pt o;
	Q rot, nxt;
	bool used;

	QuadEdge(int id_ = -1, pt o_ = pt(INF, INF)) :
		id(id_), o(o_), rot(nullptr), nxt(nullptr), used(false) {}

	Q rev() const { return rot->rot; }
	Q next() const { return nxt; }
	Q prev() const { return rot->next()->rot; }
	pt dest() const { return rev()->o; }
};

Q edge(pt from, pt to, int id_from, int id_to) {
	Q e1 = new QuadEdge(id_from, from);
	Q e2 = new QuadEdge(id_to, to);
	Q e3 = new QuadEdge;
	Q e4 = new QuadEdge;
	tie(e1->rot, e2->rot, e3->rot, e4->rot) = {e3, e4, e2, e1};
	tie(e1->nxt, e2->nxt, e3->nxt, e4->nxt) = {e1, e2, e4, e3};
	return e1;
}

void splice(Q a, Q b) {
	swap(a->nxt->rot->nxt, b->nxt->rot->nxt);
	swap(a->nxt, b->nxt);
}

void del_edge(Q& e, Q ne) { // delete e and assign e <- ne
	splice(e, e->prev());
	splice(e->rev(), e->rev()->prev());
	delete e->rev()->rot, delete e->rev();
	delete e->rot; delete e;
	e = ne;
}

Q conn(Q a, Q b) {
	Q e = edge(a->dest(), b->o, a->rev()->id, b->id);
	splice(e, a->rev()->prev());
	splice(e->rev(), b);
	return e;
}

bool in_c(pt a, pt b, pt c, pt p) { // p ta na circunf. (a, b, c) ?
	__int128 p2 = p*p, A = a*a - p2, B = b*b - p2, C = c*c - p2;
	return sarea2(p, a, b) * C + sarea2(p, b, c) * A + sarea2(p, c, a) * B > 0;
}

pair<Q, Q> build_tr(vector<pt>& p, int l, int r) {
	if (r-l+1 <= 3) {
		Q a = edge(p[l], p[l+1], l, l+1), b = edge(p[l+1], p[r], l+1, r);
		if (r-l+1 == 2) return {a, a->rev()};
		splice(a->rev(), b);
		ll ar = sarea2(p[l], p[l+1], p[r]);
		Q c = ar ? conn(b, a) : 0;
		if (ar >= 0) return {a, b->rev()};
		return {c->rev(), c};
	}
	int m = (l+r)/2;
	auto [la, ra] = build_tr(p, l, m);
	auto [lb, rb] = build_tr(p, m+1, r);
	while (true) {
		if (ccw(lb->o, ra->o, ra->dest())) ra = ra->rev()->prev();
		else if (ccw(lb->o, ra->o, lb->dest())) lb = lb->rev()->next();
		else break;
	}
	Q b = conn(lb->rev(), ra);
	auto valid = [&](Q e) { return ccw(e->dest(), b->dest(), b->o); };
	if (ra->o == la->o) la = b->rev();
	if (lb->o == rb->o) rb = b;
	while (true) {
		Q L = b->rev()->next();
		if (valid(L)) while (in_c(b->dest(), b->o, L->dest(), L->next()->dest()))
			del_edge(L, L->next());
		Q R = b->prev();
		if (valid(R)) while (in_c(b->dest(), b->o, R->dest(), R->prev()->dest()))
			del_edge(R, R->prev());
		if (!valid(L) and !valid(R)) break;
		if (!valid(L) or (valid(R) and in_c(L->dest(), L->o, R->o, R->dest())))
			b = conn(R, b->rev());
		else b = conn(b->rev(), L->rev());
	}
	return {la, rb};
}

vector<vector<int>> delaunay(vector<pt>& v) {
	int n = v.size();
	auto tmp = v;
	vector<int> idx(n);
	iota(idx.begin(), idx.end(), 0);
	sort(idx.begin(), idx.end(), [&](int l, int r) { return v[l] < v[r]; });
	for (int i = 0; i < n; i++) v[i] = tmp[idx[i]];
	assert(unique(v.begin(), v.end()) == v.end());
	vector<vector<int>> g(n);
	bool col = true;
	for (int i = 2; i < n; i++) if (sarea2(v[i], v[i-1], v[i-2])) col = false;
	if (col) {
		for (int i = 1; i < n; i++)
			g[idx[i-1]].push_back(idx[i]), g[idx[i]].push_back(idx[i-1]);
		return g;
	}
	Q e = build_tr(v, 0, n-1).first;
	vector<Q> edg = {e};
	for (int i = 0; i < edg.size(); e = edg[i++]) {
		for (Q at = e; !at->used; at = at->next()) {
			at->used = true;
			g[idx[at->id]].push_back(idx[at->rev()->id]);
			edg.push_back(at->rev());
		}
	}
	return g;
}

long double dist(pt p, pt o) {
    long double x2 = p.x-o.x, y2 = p.y-o.y;
    return sqrt(x2*x2+y2*y2);
}

long double radius(pt p1, pt p2, pt p3) {
    long double area = fabs(sarea2(p1,p2,p3));
    long double a = dist(p1,p2);
    long double b = dist(p2,p3);
    long double c = dist(p3,p1);
    return a*b*c/(area);
}

int main() { _

    int n;
    cin >> n;

    vector<pt> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    vector<vector<int>> adj = delaunay(v);
    long double ans=0;

    for(int i=0;i<n;i++) {
        // cout << 
        for(int j=0;j<(int)adj[i].size();j++) {
            ans = max(ans,radius(v[i],v[adj[i][j]],v[adj[i][(j+1)%adj[i].size()]]));
        }
    }

    cout << fixed << setprecision(15);
    cout << ans << '\n';

    return 0;
}
