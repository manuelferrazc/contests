#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define a first
#define b second
typedef long long ll;
typedef unsigned long long ull;

int n,k;
vector<pair<double,double>> v;

bool check(double x) {
    vector<double> aux(n);
    for(int i=0;i<n;i++) aux[i] = v[i].a-v[i].b*x;
    sort(aux.rbegin(),aux.rend());

    x=0;
    for(int i=0;i<k;i++) x+=aux[i];
    return x>=0;
}

int main() { _
    cout << fixed << setprecision(10);
    cin >> n >> k;
    v.resize(n);
    for(auto &i:v) cin >> i.a >> i.b;

    double l=0,r=1e5,m;

    while(r-l>1e-8) {
        m = (l+r)/2;

        if(check(m)) l=m;
        else r=m;
    }

    cout << r << '\n';

    return 0;
}
