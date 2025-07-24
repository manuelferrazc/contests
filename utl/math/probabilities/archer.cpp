#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    double ans=0, s=(double)a/b, z = (double)c/d;

    double act=1;

    for(int i=0;i<1000000;i++) {
        ans+=act*s;
        act*=(1-s)*(1-z);
    }

    cout << setprecision(10) << ans << '\n';
    return 0;
}
