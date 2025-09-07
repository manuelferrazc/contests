#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll a,b;
    cin >> a >> b;

    if(max(a&1,b&1)==0) {
        ll ans = a+b;
        while(b%4==0) {
            b>>=1;
            a<<=1;
            ans = max(ans,a+b);
        }

        ll q = b/2;
        a*=q;
        ans = max(ans,a+2);
        cout << ans << '\n';
    } else if(min(a&1,b&1)) cout << a*b+1 << '\n';
    else if(b&1) cout << -1 << '\n';
    else {
        if(b%4) cout << -1 << '\n';
        else {
            b>>=1;
            a<<=1;
            ll ans = a+b;
            while(b%4==0) {
                b>>=1;
                a<<=1;
                ans = max(ans,a+b);
            }

            ll q = b/2;
            a*=q;
            ans = max(ans,a+2);
        
            cout << ans << '\n';
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
