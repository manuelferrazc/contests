#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Point {
    double x,y;

    inline double dist(const Point &o) {
        double x2 = x-o.x, y2 = y-o.y;
        return sqrt(x2*x2+y2*y2);
    }
};

struct Edge {
    int v,u;
    double dist;

    Edge(int _v, int _u, double _d): v(_v), u(_u), dist(_d) {}

    bool operator<(const Edge &o) {
        return dist<o.dist;
    }
};

int get(int a, int *p) {
    return p[a] = (p[a]==a?a:get(p[a],p));
}

bool unir(int a, int b, int *p, int *r) {
    a = get(a,p);
    b = get(b,p);
    if(a==b) return false;

    if(r[b]>r[a]) swap(a,b);
    else if(r[a]==r[b]) r[a]++;

    p[b] = a;

    return true;
}

void solve(int t) {
    int n;
    cin >> n;
    int r[n],p[n];
    for(int i=0;i<n;i++) r[i] = 1;
    for(int i=0;i<n;i++) p[i] = i;

    Point v[n];
    for(int i=0;i<n;i++) cin >> v[i].x >> v[i].y;

    vector<Edge> e;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            e.push_back(Edge(i,j,v[i].dist(v[j])));
        }
    }

    sort(e.begin(),e.end());
    double ans = 0;
    for(auto [v1,v2,dist]:e) {
        if(unir(v1,v2,p,r)) ans+=dist;
    }

    cout << ans << '\n';
    if(t) cout << '\n';
}

int main() { _
    cout << fixed << setprecision(2);

    int t;
    cin >> t;
    while(t--) solve(t);
    return 0;
}
