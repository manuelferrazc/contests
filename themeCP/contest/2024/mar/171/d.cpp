#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll l,r;
    cin >> l >> r;

    for(ll i=30;i>=0;i--) {
        if((1LL<<i)<=r and ((1LL<<i)-1)>=l) {
            if((1LL<<i)!=l+1) cout << (1LL<<i) << ' ' << (1LL<<i)-1 << ' ' << l << '\n';
            else cout << (1LL<<i) << ' ' << (1LL<<i)-1 << ' ' << r << '\n';
            return;
        }
    }

    ll x=LLONG_MAX;
    for(ll i=62;i>=0;i--) if(x>r and (x^(1LL<<i))>=l) x^=1LL<<i;
    
    ll ababa = 0;
    for(ll i=62;i>=0;i--) if(ababa<l and (ababa+(1LL<<i))<=r) ababa+=1LL<<i;
    
    if(min(ababa,x)>l) cout << /* "case 1 " << */ ababa << ' ' << x << ' ' << l << '\n';
    else if(max(ababa,x)<r) cout << /*"case 2 " << */ ababa << ' ' << x << ' ' << r << '\n';
    else if(min(ababa,x)<max(ababa,x)-1) cout << /* "case 3 " << */ ababa << ' ' << x << ' ' << max(ababa,x)-1 << '\n';
    else if(max(ababa,x)>min(ababa,x)+1) cout << /* "case 4 " << */ ababa << ' ' << x << ' ' << min(ababa,x)+1 << '\n';
    else cout << /* "case 5 " << */ max(ababa,x) << ' ' << min(ababa,x) << ' ' << (min(ababa,x)+max(ababa,x))/2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
