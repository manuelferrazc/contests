#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<bool> v((4e5)+10,true);

void solve() {
    ll n;
    cin >> n;

    vector<ll> ans;
    set<ll> sp,si;
    for(ll i=1;i<=n;i+=2) si.insert(i);
    for(ll i=2;i<=n;i+=2) sp.insert(i);

    for(auto it = si.begin();it!=si.end();it++) {
        for(auto i2 = sp.begin();i2!=sp.end();i2++) {
            if(not v[*it+*i2]) {
                for(auto i:si) if(i!=*it) cout << i << ' ';
                cout << *it << ' ' << *i2 << ' ';
                for(auto i:sp) if(i!=*i2) cout << i << ' ';
                cout << '\n';
                return;
            }
        }
    }
    cout << "-1\n";

}

int main() { _
    for(ull i=2;i<v.size();i++) {
        if(not v[i]) continue;
        for(ull j=i+i;j<v.size();j+=i) v[j] = false;
    }

    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
