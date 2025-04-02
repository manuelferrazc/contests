#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,s;
    cin >> n >> s;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
    vector<ll> sp;
    sp.push_back(0);
    for(auto &i:v) sp.push_back(sp.back()+i);
    ll sum = sp.back();
    ll x = s%sum;
    if(not x) {
        cout << "Yes\n";
        return 0;
    }
    for(auto &i:v) sp.push_back(sp.back()+i);

    for(ull i=0;i<sp.size();i++) {
        auto it = lower_bound(sp.begin()+i+1,sp.end(),x+sp[i]);
        if(it!=sp.end() and *it==x+sp[i]) {
            cout << "Yes\n";
            return 0;
        }
        it = lower_bound(sp.begin()+i,sp.end(),x+sp[i]+sum);
        if(it!=sp.end() and *it==x+v[i]+sum) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
