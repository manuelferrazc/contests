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

    // bool cx=false,xy=false;
    for(ll i=0;i<40;i++) {
        // if(cx) {
        //     cx=false;
        //     x+=(1LL<<i);
        // }def f(x,y,k): return (x+y+2*k)==((x+k)^(y+k))
        // if(cy) {
        //     cy=false;
        //     y+=(1LL<<i);
        // }

        if(((x>>i)&1LL) and ((y>>i)&1LL)) {
            for(;i<60;i++) {
                ll xi = ((x>>i)&1LL);//, xi1 = ((x>>(i+1))&1LL);
                ll yi = ((y>>i)&1LL);//, yi1 = ((y>>(i+1))&1LL);
                if(yi==xi) {
                    a|=1LL<<i;
                } else {
                    a|=1LL<<i;
                    if(xi) {
                        int j;
                        for(j=i+1;((x>>j)&1LL);j++) 
                        x|=1LL<<j;
                    } else {
                        int j;
                        for(j=i+1;((y>>j)&1LL);j++) 
                        y|=1LL<<j;
                    }
                    break;
                }

            }
            // // cout << "ababa\n";
            // a+=1LL<<i;
            // if((x>>i)&1LL) x+=1LL<<i;
            // if((y>>i)&1LL) y+=1LL<<i;
        }
    }

    cout << a << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
