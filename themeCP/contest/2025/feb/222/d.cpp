#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


map<ll,ll> dp;
map<ll,vector<ll>> s;

ll ddp(ll size) {
    if(dp.count(size)) return dp[size];
    if(s.count(size)==0LL) {
        dp.insert(make_pair(size,size));
        return size;
    }

    ll si = size;

    for(auto x:s.at(size)) si = max(si,ddp(size+x-1));
    dp.insert({size,si});
    return si;
}

void solve() {
    ll n;
    cin >> n;
    dp.clear();
    s.clear();

    ll x;
    cin >> x;
    for(ll i=2;i<=n;i++) {
        cin >> x;
        if(not s.count(x+i-1)) s.insert(make_pair(x+i-1,vector<ll>()));
        s[x+i-1].push_back(i);
    }

    cout << ddp(n) << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
