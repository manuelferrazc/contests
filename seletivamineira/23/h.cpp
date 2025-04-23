#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    string s;
    ll k;
    cin >> s >> k;
    vector<ll> v(26);
    for(ll i=0;i<26;i++) cin >> v[i];

    ll m = *max_element(v.begin(),v.end());

    ll ans=0;
    for(ll i=0;i<s.size();i++) ans+=(i+1)*(v[s[i]-'a']);

    for(ll i=0;i<k;i++) ans+=(s.size()+i+1)*m;

    cout << ans << '\n';
    
    return 0;
}
