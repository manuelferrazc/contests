#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ull k,x; cin >> k;
    vector<ull> v(k);
    for(ull i=0;i<k;i++) cin >> v[i];

    x = k-2;
    sort(v.begin(),v.end());
    for(ull i=0;i<k;i++) {
        if(x%v[i]) continue;
        auto it = lower_bound(v.begin(),v.end(),x/v[i]);
        if(*it==x/v[i]) {cout << v[i] << ' ' << *it << '\n'; return;}
    }
}

int main() { 
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
