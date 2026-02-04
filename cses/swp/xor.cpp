#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

inline int next(ll x, ll a, ll b, ll c) {
    return (a*x+b)%c;
}

int main() { _
    int n,k;
    cin >> n >> k;

    ll x,a,b,c;
    cin >> x >> a >> b >> c;

    int s = x;
    int xi = x;
    
    for(int i=1;i<k;i++) {
        xi = next(xi,a,b,c);
        s^=xi;
    }
    
    int ans = s;
    for(int i=k;i<n;i++) {
        s^=x;

        x = next(x,a,b,c);
        xi = next(xi,a,b,c);

        s^=xi;
        ans^=s;
    }

    cout << ans << '\n';


    return 0;
}
