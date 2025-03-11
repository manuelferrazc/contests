#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll t1(ll x) {
    ll r=LLONG_MAX;
    for(ll i=62;;i--) {
        r = r&(~(1LL<<i));
        if(x&(1LL<<i)) return r;
    }
    return r;
}

ll t2(ll x) {
    ll r=0;
    ll c=0;
    for(int i=0;i<40;i++) {
        if(x&(1LL<<i)) {
            r=1LL<<i;
            c=i;
        }
    }
    for(int i=c-1;i>=0;i--) {
        if((x>>i)&1LL) r=r|(1>>i);
    }
    return r;
}

void solve() {
    ll x;
    cin >> x;

    ll c=t1(x);
    if(c<x and (c+x>(c^x)) and (c+(c^x)>x) and (x+(c^x)>c)) cout << c << '\n';
    else {
        c=c^x;
        if(c<x and (c+x>(c^x)) and (c+(c^x)>x) and (x+(c^x)>c)) cout << c << '\n';
        else {
            c=t1(x);
            if(c<x and (c+x>(c^x)) and (c+(c^x)>x) and (x+(c^x)>c)) cout << c << '\n';
            else {
                c=c^x;
            if(c<x and (c+x>(c^x)) and (c+(c^x)>x) and (x+(c^x)>c)) cout << c << '\n';
            else cout << "-1\n";
            }
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
