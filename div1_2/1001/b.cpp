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
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    if(v[0]<=2*(n-1) or v.back()<=2*(n-1)) {
        cout << "no\n";
        return;
    }
    for(ll i=1;i<n-1;i++) {
        if(v[i]<=max(2*i,2*(n-i-1))) {
            cout << "no\n";
            return;
        }
    }
    
    cout << "yes\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
