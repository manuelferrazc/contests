#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007LL;
const ll p = 998244353LL;

int main() { _
    string a,b;
    ll k;
    cin >> a >> b >> k;

    ll n = a.size();

    vector<ll> v;
    v.push_back(1);
    for(ll i=1;i<n;i++) v.push_back(v.back()*p%mod);

    set<ll> ans;

    for(ll i=0;i<n;i++) {
        ll h=0,qtd=0;
        for(ll j=i;j<n;j++) {
            if(b[a[j]-'a']=='0') qtd++;
            if(qtd>k) break;
            h = (h+v[j-i]*(a[j]-'a'+1LL))%mod;
            
            ans.insert(h);
        }
    }

    cout << ans.size() << '\n';

    return 0;
}
