#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,ans=LLONG_MAX;
    cin >> n;
    
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(ll i=0;i<n;i++) {
        ll b=i;
        while(i<n-1 and v[i+1]==v[b]) i++;
        ll c=0;
        if(b) c+=b*v[b];
        if(i<n-1) c+=v[b]*(n-i-1);
        ans = min(ans,c); 
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
