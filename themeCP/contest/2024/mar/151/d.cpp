#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for(ll i=0;i<n;i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    map<ll,ll> ans;
    sort(a.begin(),a.end());

    ll smallers=0,biggers=0;
    for(int i=1;i<n;i++) biggers+=a[i]-a[0];
    
    ans[a[0]] = n+smallers+biggers;
    for(ll i=1;i<n;i++) {
        smallers+=i*(a[i]-a[i-1]);
        biggers-=(n-i)*(a[i]-a[i-1]);
        ans[a[i]] = n+smallers+biggers;
    }

    for(ll i:b) cout << ans[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
