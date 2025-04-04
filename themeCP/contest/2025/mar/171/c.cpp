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
    vector<ll> v;

    for(ll i=62;i>=0;i--) if((1LL<<i)&n) v.push_back(n^((1LL<<i)));
    if(v.back()==0) v.pop_back();
    v.push_back(n);
    cout << v.size() << '\n';
    for(ll i:v) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
