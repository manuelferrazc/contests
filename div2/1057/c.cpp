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

    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end());

    vector<ll> ans;
    vector<ll> extra;
    while(v.size()) {
        if(v.size()>1ull and v.back()==v[v.size()-2]) {
            ans.push_back(v.back());
            ans.push_back(v.back());
            v.pop_back();
            v.pop_back();
        } else {
            extra.push_back(v.back());
            v.pop_back();
        }
    }

    sort(extra.begin(),extra.end());

    ll mx2 = 0, mx1 = 0, act = accumulate(ans.begin(),ans.end(),0ll);

    for(ull i=1;i<extra.size();i++) {
        if(act+extra[i-1]>extra[i]) {
            mx2 = act+extra[i-1]+extra[i];
        }
    }

    for(ull i=0;i<extra.size();i++) {
        if(act>extra[i]) mx1 = act+extra[i];
    }

    if(ans.size()>2ull) cout << max({mx2,mx1,act}) << '\n';
    else cout << max(mx2,mx1) << '\n';
    // for(ull i=0;i<min(2ul,extra.size());i++) ans.push_back(extra[i]);

    // sort(ans.begin(),ans.end());
    // ll per = accumulate(ans.begin(),ans.end(),-ans.back());
    // // for(ll i:ans) cout << i << ' ';
    // // cout << '\n';
    // // cout << per << ' ';
    // if(ans.size()>2ull and per>ans.back()) cout << per+ans.back() << '\n';
    // else cout << 0 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
