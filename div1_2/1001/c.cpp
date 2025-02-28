#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
ll n;

vector<ll> mk(vector<ll> &v) {
    vector<ll> ret(v.size()-1ULL);
    for(ull i=1;i<v.size();i++) ret[i-1] = v[i]-v[i-1];
    return ret;   
}

ll brute(vector<ll> v) {
    if(v.size()==1ULL) return v[0];

    ll s = accumulate(v.begin(),v.end(),0LL);

    return max(((ll)v.size()!=n? abs(s):s),abs(brute(mk(v))));
}

void solve() {
    cin >> n;

    vector<ll> v(n);
    for(auto &i:v) cin >> i;

    cout << brute(v) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
