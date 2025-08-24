#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _ // dont know how to solve this
    ll x;
    cin >> x;

    vector<ll> ans;
    vector<ll> sq;
    for(ll i=0;i<=3e7;i++) sq.push_back(i*i-x);

    for(ll i = -3e7;i<=3e7;i++) {
        auto it = lower_bound(sq.begin(),sq.end(),i*(i+1));
        if(it!=sq.end() and *it == i*(i+1)) ans.push_back(i);
    }

    cout << ans.size() << '\n';
    if(ans.size()) {
        for(ll i:ans) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
