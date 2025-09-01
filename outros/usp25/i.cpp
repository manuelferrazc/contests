#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

// Geometria

typedef double ld;
const ld DINF = 1e18;
const ld pi = acos(-1.0);
const ld eps = 1e-9;

#define sq(x) ((x)*(x))

bool eq(ld a, ld b) {
	return abs(a - b) <= eps;
}

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
	friend istream& operator >> (istream& in, line& r) {
		return in >> r.p >> r.q;
	}
};

// PONTO & VETOR

ld dist(pt p, pt q) { // distancia
	return hypot(p.y - q.y, p.x - q.x);
}

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) { // se p, q, r sao ccw
	return sarea(p, q, r) > eps;
}

bool isinseg(pt p, line r) { // se p pertence ao seg de r
	pt a = r.p - p, b = r.q - p;
	return eq((a ^ b), 0) and (a * b) < eps;
}

bool interseg(line r, line s) { // se o seg de r intersecta o seg de s
	if (isinseg(r.p, s) or isinseg(r.q, s)
		or isinseg(s.p, r) or isinseg(s.q, r)) return 1;

	return ccw(r.p, r.q, s.p) != ccw(r.p, r.q, s.q) and
			ccw(s.p, s.q, r.p) != ccw(s.p, s.q, r.q);
}


ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}



int main() { _
    int n;
    cin >> n;
    vector<vector<pair<int,ld>>> adj(n+1);

    vector<pt> v(n);
    for(auto &p:v) cin >> p;

    pt t;
    cin >> t;

    const ld area = polarea(v);

    for(int i=0;i<n-1;i++) {
        adj[i].push_back({i+1,dist(v[i],v[i+1])});
        adj[i+1].push_back({i,dist(v[i],v[i+1])});

        for(int j=i+2;j<n;j++) {
            bool ok = true;
            for(int k=0;k<n;k++) {
                if(k==i or (k+1)%n==i or k==j or (k+1)%n==j) continue;
                if(interseg(line(v[i],v[j]),line(v[k],v[(k+1)%n]))) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                vector<pt> v1,v2;
                v1.push_back(v[i]);
                v2.push_back(v[i]);

                for(int k=i+1;k<=j;k++) v1.push_back(v[k]);
                for(int k=j;k!=i;k = (k+1)%n) v2.push_back(v[k]);

                if(not eq(area,polarea(v1)+polarea(v2))) ok = false;
            }

            if(ok) {
                adj[i].push_back({j,dist(v[i],v[j])});
                adj[j].push_back({i,dist(v[i],v[j])});
            }
        }
    }

    for(int i=0;i<n;i++) {
        line l(v[i],t);
        bool ok = true;
        for(int j=0;j<n;j++) {
            if(j==i or (j+1)%n==i) continue;
            if(interseg(l,line(v[j],v[(j+1)%n]))) {
                ok = false;
                break;
            }
        }

        if(ok) {
            adj[i].push_back({n,dist(v[i],t)});
            adj[n].push_back({i,dist(v[i],t)});
        }
    }


    priority_queue<pair<ld,int>,vector<pair<ld,int>>,greater<pair<ld,int>>> pq;
    vector<ld> dist(n+1,INT_MAX);
    dist[0] = 0;
    pq.push({0,0});

    while(not pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();

        if(!eq(d,dist[u])) continue;

        for(auto [vis,dd]:adj[u]) {
            if(dist[vis]>dd+d and not eq(dist[vis],dd+d)) {
                dist[vis] = dd+d;
                pq.push({dist[vis],vis});
            }
        }
    }

    cout << fixed << setprecision(9) << 2*dist.back() << '\n';

    return 0;
}
