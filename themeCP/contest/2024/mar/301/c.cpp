#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    multiset<int> s;
    for(ll i=0;i<n;i++) {
        int x;
        cin >> x;
        s.insert(x);
    }

    while(s.size()) {
        if(s.size()==1ULL) break;
        auto it = s.begin();
        if(s.count(((*it)^INT_MAX))) {
            n--;
            s.erase(s.lower_bound(((*it)^INT_MAX)));
        } s.erase(it);
    }

    cout << n << '\n';
}

int main() { 
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
