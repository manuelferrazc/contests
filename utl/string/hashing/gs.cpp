#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod1 = 1'000'000'007LL;
const ll mod2 = 1'000'000'009LL;
const ll p = 31LL;

ll fexp(ll n, ll e, ll m) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1,m);
    r = r*r%m;
    if(e&1) r = r*n%m;
    return r;
}

int main() { _
    string a,b;
    ll k;
    cin >> a >> b >> k;

    ll n = a.size();

    vector<pair<ll,ll>> ans;

    for(ll i=0;i<n;i++) {
        pair<ll,ll> h;
        h.ff = h.ss = 0;
        ll qtd=0;

        for(ll j=i;j<n;j++) {
            if(b[(a[j]-'a')]=='0') {
                if(qtd==k) break;
                qtd++;
            }
            h.ff = (h.ff+fexp(p,j-i,mod1)*(a[j]-'a'+1LL))%mod1;
            h.ss = (h.ss+fexp(p,j-i,mod2)*(a[j]-'a'+1LL))%mod2;

            ans.push_back(h);
        }
    }

    sort(ans.begin(),ans.end());
    ll x=!ans.empty();
    for(ull i=1;i<ans.size();i++) if(ans[i]!=ans[i-1]) x++;
    cout << x << '\n';

    return 0;
}
