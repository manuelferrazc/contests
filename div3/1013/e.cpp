#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<short> v(10'000'001,0);

void solve() {
    ll n;
    cin >> n;

    ll ans=0;
    short um = 1;
    for(ll i=2;i<=n;i++) ans+= max(um,v[i]);
    
    cout << ans << '\n';
}

int main() { 
    for(ull i=2;i<v.size();i++) {
        if(v[i]) continue;
        for(ull j=i+i;j<v.size();j+=i) v[j]++;
    }

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
