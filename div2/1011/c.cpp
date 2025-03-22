#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,y,a=0;
    cin >> x >> y;

    if(x==y) {
        cout << "-1\n";
        return;
    }

    for(ll i=0;i<40;i++) {
        if(((x>>i)&1LL) and ((y>>i)&1LL)) {
            for(;;i++) {
                if(i>=50LL) {
                    cout << "-1\n";
                    return;
                }
                ll xi = ((x>>i)&1LL), xi1 = ((x>>(i+1LL))&1LL);
                ll yi = ((y>>i)&1LL), yi1 = ((y>>(i+1LL))&1LL);
                
                a|=1LL<<i;
                if((xi>yi and yi1>xi1) or (xi<yi and yi1<xi1)) break;

            }
        }
        if ((x+y+a+a)==((x+a)^(y+a))) {
            cout << a << '\n';
            return;
        }
    }
    if ((x+y+a+a)==((x+a)^(y+a))) cout << a << '\n';
    else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}