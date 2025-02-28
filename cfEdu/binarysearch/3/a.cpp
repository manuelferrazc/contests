#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define x first
#define s second
typedef long long ll;
typedef unsigned long long ull;

int n;
vector<pair<double,double>> v;

bool check(double t) {
    auto p = make_pair(v[0].x-t*v[0].s,v[0].x+t*v[0].s);

    for(int i=1;i<n;i++) {
        p.first = max(v[i].x-t*v[i].s,p.first);
        p.second = min(v[i].x+t*v[i].s,p.second);
        if(p.first>p.second) return false;
    }
    return true;
}

int main() { _
    cout << fixed << setprecision(13);
    cin >> n;

    v.resize(n);
    for(auto &i:v) cin >> i.x >> i.s;

    double l=0,r=(1e9)+3,m;
    
    while(abs(r-l)>0.000001) {
        m = (l+r)/2;
        if(check(m)) r=m;
        else l=m;
    }

    cout << l << '\n';

    return 0;
}
