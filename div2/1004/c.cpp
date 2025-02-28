#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool check(ll x) {
    string s = to_string(x);
    for(auto i:s) if(i=='7') return true;
    return false;
}

ll n;

ll count(ll x) {
    for(ll i=0;i<9;i++) if(check(n+x*i)) return i;
    return 9LL;
}

void solve() {
    cin >> n;
    ll ans = count(9);
    for(ll i=99;i<n*10;i=i*10+9) ans=min(ans,count(i));
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
