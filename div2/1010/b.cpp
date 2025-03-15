#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll minx(ll x, ll n, ll m) {
    while(x!=0 and (n>0 or m>0)) {
        if(m>0) {
            if(x==1) {
                m=0;
                continue;
            }
            m--;
            if(x&1) x++;
            x>>=1;
        } else {
            n--;
            x>>=1;
        }
    }
    return x;
}

ll maxx(ll x, ll n, ll m) {
    while(x!=0 and (n>0 or m>0)) {
        if(n) {
            n--;
            x>>=1;
        } else if(x==1) break;
        else {
            m--;
            if(x&1) x++;
            x>>=1;
        }
    }
    return x;
}

void solve() {
    ll n,m,x;
    cin >> x >> n >> m;

    cout << minx(x,n,m) << ' ' << maxx(x,n,m) << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
