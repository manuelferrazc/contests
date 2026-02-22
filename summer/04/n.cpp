#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ld eps = 1e-9;

bool eq(ld a, ld b) {
    return abs(a-b)<=eps;
}

struct pt {
    ld x, y;
    pt(ld _x=0, ld _y = 0) : x(_x), y(_y) {}

    bool operator < (const pt p) const {
        if(!eq(x,p.x)) return x<p.x;
        if(!eq(y,p.y)) return y<p.y;
        return false;
    }

    bool operator == (const pt p) const {
        return eq(x,p.x) and eq(y,p.y);
    }

    pt operator + (const pt p) const { return pt(x+p.x, y+p.y ); }
    pt operator - (const pt p) const { return pt(x-p.x, y-p.y ); }
    pt operator * (const ld c) const { return pt(x*c  , y*c   ); }
    pt operator / (const ld c) const { return pt(x/c  , y/c   ); }
    ld operator * (const pt p) const { return x*p.x + y*p.y; }
    ld operator ^ (const pt p) const { return x*p.y - y*p.x; }

    friend istream& operator >>(istream &in, pt &p) {
        return in >> p.x >> p.y;
    }
};

struct line {
    pt p,q;
    line() {}
    line(pt _p, pt _q): p(_p), q(_q) {}
};

ld dist(pt p, pt q) {
    return hypot(p.y-q.y,p.x-q.x);
}

ld sarea(pt p, pt q, pt r) {
    return ((q-p)^(r-q))/2;
}

bool ccw(pt p, pt q, pt r) {
    return sarea(p,q,r)>eps;
}

pt proj(pt p, line r) {
    if(r.p==r.q) return r.p;
    r.q = r.q-r.p;
    p = p - r.p;
    pt proj = r.q*((p*r.q)/(r.q*r.q));
    return proj+r.p;
}

vector<pt> convex_hull(vector<pt> v) {
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    if(v.size()<=1) return v;
    vector<pt> l,u;
    for(int i=0;i<v.size();i++) {
        while(l.size()>1 and !ccw(l.end()[-2],l.end()[-1],v[i]))
            l.pop_back();
        l.push_back(v[i]);
    }
    for(int i=v.size()-1;i>=0;i--) {
        while(u.size()>1 and !ccw(u.end()[-2],u.end()[-1],v[i]))
            u.pop_back();
        u.push_back(v[i]);
    }
    l.pop_back();
    u.pop_back();
    for(pt i:u) l.push_back(i);
    return l;
}

int c=1;

void solve(int &n) {
    vector<pt> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    v = convex_hull(v);

    ld ans = 1e12;
    n = v.size();
    for(int i=0;i<n;i++) {
        ld mx = 0;
        line l(v[i],v[(i+1)%n]);

        for(int j=(i+2)%n;j!=i;j = (j+1)%n) {
            mx = max(mx,dist(v[j],proj(v[j],l)));
        }

        ans = min(ans,mx);
    }
    
    if(not eq(ans,((ll)(ans*100))/100.0)) ans+=0.01;
    cout << "Case " << c++ << ": " << ans << '\n';

    cin >> n;
}

int main() { _
    cout << fixed << setprecision(2);
    int n;
    cin >> n;
    while(n) solve(n);
    return 0;
}
