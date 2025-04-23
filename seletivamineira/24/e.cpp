#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define y second
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
const ld eps = 1e-9;

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

ld sarea(pt p, pt q, pt r) { // area com sinal
	return ((q-p)^(r-q))/2;
}

bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return eq(sarea(p, q, r), 0);
}

double dist(pt &p1, pt &p2) {
    return sqrt(pow(p1.x-p2.x,2)+pow(p1.y-p2.y,2));
}

double area(pt &p1,pt &p2,pt &p3) {
    double a = dist(p1,p2), b = dist(p2,p3), c = dist(p3,p1);
    double s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}

ld polarea(vector<pt> v) { // area do poligono
	ld ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret);
}

int main() { _
    ll n;
    cin >> n;
    vector<pair<pt,int>> v(n);
    int a0=1;
    for(auto &i:v) {
        cin >> i.x.x >> i.x.y;
        i.y = a0++;
    }

    sort(v.begin(),v.end());

    ll x;
    for(ll i=2;i<n;i++) {
        if(not col(v[0].x,v[1].x,v[i].x)) {
            x=i;
            break;
        }
    }

    double a = polarea({v[0].x,v[1].x,v[x].x});
    for(ll i=x+1;i<n;i++) {
        if(col(v[0].x,v[1].x,v[i].x)) continue;
        double ar = polarea({v[0].x,v[1].x,v[i].x});
        if(ar<a) {
            a=ar;
            x=i;
        }
    }

    cout << v[0].y << ' ' << v[1].y << ' ' << v[x].y << '\n';
    return 0;
}
