#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll k,a,b,x,y;
    cin >> k >> a >> b >> x >> y;
    ll ans=0;
    if(x<=y) {
        if(k>=a) ans = (k-a)/x;
        k-=ans*x;
        if(k>=a) {
            ans++;
            k-=x;
        }   
 
        if(k>=b) {
            ans += (k-b)/y;
            k-=((k-b)/y)*y;
            if(k>=b) ans++;
        }
    } else {
        if(k>=b) ans = (k-b)/y;
        k-=ans*y;
        if(k>=b) {
            ans++;
            k-=y;   
        }
        // cout << ans << ' '; 
        if(k>=a) {
            ans += (k-a)/x;
            k-=((k-a)/x)*x;
            if(k>=a) ans++;
        }
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
