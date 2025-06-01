#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
    return abs(a - b) <= eps;
}

namespace dd {

    
    struct pt { // ponto
	ld x, y;
	pt(ld x_ = 0, ld y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
        if (!eq(x, p.x)) return x < p.x;
		if (!eq(y, p.y)) return y < p.y;
		return 0;
	}
	bool operator == (const pt p) const {
        return eq(x, p.x) and eq(y, p.y);
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const ld c) const { return pt(x*c  , y*c  ); }
	pt operator / (const ld c) const { return pt(x/c  , y/c  ); }
	ld operator * (const pt p) const { return x*p.x + y*p.y; }
	ld operator ^ (const pt p) const { return x*p.y - y*p.x; }
	friend istream& operator >> (istream& in, pt& p) {
        return in >> p.x >> p.y;
	}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
    bool operator==(const line &l) {
        return (p==l.p and q==l.q) or (p==l.q and q==l.p);
    }
	friend istream& operator >> (istream& in, line& r) {
        return in >> r.p >> r.q;
	}
    friend ostream & operator<<(ostream &out,line &r) {
        return out << r.p.x << ' ' << r.p.y << " ---- " << r.q.x << ' ' << r.q.y;
    }
};

// PONTO & VETOR

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

ld get_t(pt v, line r) { // retorna t tal que t*v pertence a reta r
	return (r.p^r.q) / ((r.p-r.q)^v);
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	// if (isinseg(r.p, s) or isinseg(r.q, s)
    // or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
} // atencao aq

// se o ponto ta dentro do poligono: retorna 0 se ta fora,
// 1 se ta no interior e 2 se ta na borda
int inpol(vector<pt>& v, pt p) { // O(n)
	int qt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (p == v[i]) return 2;
		int j = (i+1)%v.size();
		if (eq(p.y, v[i].y) and eq(p.y, v[j].y)) {
			if ((v[i]-p)*(v[j]-p) < eps) return 2;
			continue;
		}
		bool baixo = v[i].y+eps < p.y;
		if (baixo == (v[j].y+eps < p.y)) continue;
		auto t = (p-v[i])^(v[j]-v[i]);
		if (eq(t, 0)) return 2;
		if (baixo == (t > eps)) qt += baixo ? 1 : -1;
	}
	return qt != 0;
}



}

namespace td {
struct pt { // ponto
        ld x, y, z;
        pt(ld x_ = 0, ld y_ = 0, ld z_ = 0) : x(x_), y(y_), z(z_) {}
        bool operator < (const pt p) const {
                if (!eq(x, p.x)) return x < p.x;
                if (!eq(y, p.y)) return y < p.y;
                if (!eq(z, p.z)) return z < p.z;
                return 0;
        }
        bool operator == (const pt p) const {
                return eq(x, p.x) and eq(y, p.y) and eq(z, p.z);
        }
        pt operator + (const pt p) const { return pt(x+p.x, y+p.y, z+p.z); }
        pt operator - (const pt p) const { return pt(x-p.x, y-p.y, z-p.z); }
        pt operator * (const ld c) const { return pt(x*c  , y*c  , z*c  ); }
        pt operator / (const ld c) const { return pt(x/c  , y/c  , z/c  ); }
        ld operator * (const pt p) const { return x*p.x + y*p.y + z*p.z; }
        pt operator ^ (const pt p) const { return pt(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x); }
        friend istream& operator >> (istream& in, pt& p) {
                in >> p.x >> p.y >> p.z;
                return in;
        }
};
 
struct line { // reta
        pt p, q;
        line() {}
        line(pt p_, pt q_) : p(p_), q(q_) {}
        friend istream& operator >> (istream& in, line& r) {
                return in >> r.p >> r.q;
        }
        friend ostream & operator<<(ostream &out,line &r) {
            return out << r.p.x << ' ' << r.p.y << " ---- " << r.q.x << ' ' << r.q.y;
        }
};
 
struct plane { // plano
        array<pt, 3> p;  // pontos que definem o plano
        array<ld, 4> eq; // equacao do plano
        plane() {}
        plane(pt p_, pt q_, pt r_) : p({p_, q_, r_}) { build(); }
 
        friend istream& operator >> (istream& in, plane& P) {
                return in >> P.p[0] >> P.p[1] >> P.p[2];
                P.build();
        }
        void build() {
                pt dir = (p[1] - p[0]) ^ (p[2] - p[0]);
                eq = {dir.x, dir.y, dir.z, dir*p[0]*(-1)};
        }
};
 
// distancia de ponto a plano com sinal
ld sdist(pt p, plane P) {
        return P.eq[0]*p.x + P.eq[1]*p.y + P.eq[2]*p.z +  P.eq[3];
}
 
// intersecao de plano e segmento
// BOTH = o segmento esta no plano
// ONE = um dos pontos do segmento esta no plano
// PARAL = segmento paralelo ao plano
// CONCOR = segmento concorrente ao plano
enum RETCODE {BOTH, ONE, PARAL, CONCOR};
pair<RETCODE, pt> intersect(plane &P, line r) {
    ld d1 = sdist(r.p, P);
    ld d2 = sdist(r.q, P);
    if (eq(d1, 0) and eq(d2, 0))
                return pair(BOTH, r.p);
    if (eq(d1, 0))
                return pair(ONE, r.p);
    if (eq(d2, 0))
                return pair(ONE, r.q);
    if ((d1 > 0 and d2 > 0) or (d1 < 0 and d2 < 0)) {
        if (eq(d1-d2, 0)) return pair(PARAL, pt());
        return pair(CONCOR, pt());
    }
    ld frac = d1 / (d1 - d2);
    pt res = r.p + ((r.q - r.p) * frac);
    return pair(ONE, res);
}
 
}

int main() { _
    int n;
    cin >> n;
    td::pt pico,sun;
    cin >> pico >> sun;

    if(pico.z+eps>=sun.z)  {
        cout << "S\n";
        return 0;
    }

    vector<dd::pt> v(n);
    for(dd::pt &i:v) cin >> i;

    dd::pt intc(pico.x,pico.y);
    ld dx = sun.x-pico.x,dy = sun.y-pico.y, dz = sun.z-pico.z;
    intc.x -= (pico.z/dz)*dx;
    intc.y -= (pico.z/dz)*dy;
    // cout << intc.x << ' ' << intc.y << ' ' << '\n';
    if(dd::inpol(v,intc)==0) {
        cout << "S\n";
        return 0;
    }

    for(int i=0;i<n;i++) {
        dd::line a(intc,v[i]);
        // cout << a << '\n';

        for(int j=1;j<n-1;j++) {
            dd::line b(v[(i+j)%n],v[(i+j+1)%n]);
            if(a==b or (dd::col(a.p,a.q,b.p) and dd::col(a.p,a.q,b.q))) continue;
            if(dd::interseg(a,b)) {
                // cout << a.p.x << ' ' << a.p.y << " --- " << a.q.x << ' ' << a.q.y << '\n';
                // cout << b.p.x << ' ' << b.p.y << " --- " << b.q.x << ' ' << b.q.y << '\n';
                cout << "S\n";
                return 0;
            }
        }
    }

    cout << "N\n";

    return 0;
}
