#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    double c;
    cin >> c;
    cout << fixed << setprecision(10);

    double l = 0, r=1e6;
    while(r-l>1e-8) {
        double m = (l+r)/2;
        double fx = m*m+sqrt(m);
        if(fx>c) r=m;
        else l=m;
    }

    cout << l << '\n';
    return 0;
}
