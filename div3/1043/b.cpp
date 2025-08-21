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
    ll p = 10;
    vector<ll> ans;
    while(true) {
        if(n%(p+1)==0) {
            ans.push_back(n/(p+1));
        }
        p*=10;
        if(p==1000000000000000000LL) break;
    }

    reverse(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for(auto i:ans) cout << i << ' ';
    if(ans.size()) cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
