#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,x;
    cin >> n >> x;

    vector<ll> v(n), sp;
    for(ll &i:v) cin >> i;

    sp.push_back(v[0]);
    for(ll i=1;i<n;i++) sp.push_back(v[i]+sp.back());

    map<ll,ll> s;
    for(ll i:sp) s[i]++;

    ll ans = s.count(x) ? s[x]:0;
    s[v[0]]--;
    
    if(s[v[0]]==0) s.erase(v[0]);
    for(ll i=1;i<n;i++) {
        if(s.count(x+sp[i-1])) ans+=s.at(x+sp[i-1]);
        
        if((--s[sp[i]])==0) s.erase(sp[i]);
    }

    cout << ans << '\n';

    return 0;
}
