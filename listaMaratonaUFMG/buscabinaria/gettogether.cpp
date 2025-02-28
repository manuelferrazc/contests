#include <bits/stdc++.h>
#include <utility>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

struct p {
    ll p, v;

    pair<double,double> range(double t) {
        return make_pair(p-v*t, p+v*t);
    }
};

bool testa(vector<p> &v, double t) {
    auto p = v.front().range(t);

    for(ull i=1;i<v.size();i++) {
        auto p2 = v[i].range(t);
        if(p2.f>p.s or p.f>p2.s) return false;
        p.f = max(p.f,p2.f);
        p.s = min(p.s,p2.s);
    }
    return true;
}

int main() { _
    ll n;
    cin >> n;

    vector<p> v(n);
    for(auto &i:v) cin >> i.p >> i.v;

    double a = 0, b = 1e9;

    while(fabs(a-b)>1e-6) {
        double m = (a+b)/2;

        if(testa(v,m)) b = m;
        else a = m;
    }

    cout << fixed << setprecision(7);
    cout << a << '\n';
    
    return 0;
}
