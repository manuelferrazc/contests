#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    ll u=0,d=0;
    for(char i:s) {
        if(i=='-') u++;
        else d++;
    }

    ll ans=0;
    
    for(ll i=1;i<u;i++) ans=max(ans,i*d*(u-i));
    
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
