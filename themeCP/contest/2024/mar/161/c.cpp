#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    
    double ans=0,nant=0;

    for(int i=0;i<1000000;i++) {
        ans+=(1-nant)*(a/b);
        nant+=(1-nant)*(a/b);
        nant+=(1-nant)*(c/d);
    }

    cout << fixed << setprecision(13) << ans << '\n';
    return 0;
}
