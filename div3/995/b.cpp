#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,a,b,c;
    cin >> n >> a >> b >> c;

    ll ans = n/(a+b+c);
    ans*=3;

    n%=(a+b+c);
    if(n) {ans++;n-=a;}
    if(n>0) {ans++;n-=b;}
    if(n>0) ans++;
    cout << ans << '\n';

}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
