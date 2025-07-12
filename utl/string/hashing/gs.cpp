#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll fexp(ll n, ll e, ll m) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1,m);
    r = r*r%m;
    if(e&1) r = r*n%m;
    return r;
}

struct Hash {
    ll mod,b;
    vector<ll> h,p;

    Hash(string &s, ll _mod, ll _b) : mod(_mod), b(_b), h(s.size()), p(s.size()) {
        p[0] = 1;
        h[0] = (s[0]-'a'+1);

        for(int i=1;i<s.size();i++) {
            p[i] = p[i-1]*b%mod;
            h[i] = (h[i-1]*b+(s[i]-'a'+1))%mod;
        }
    }

    ll get(ll l, ll r) {
        if(l==0) return h[r];
        return ((h[r]-(h[l-1]*p[r-l+1])%mod)+mod)%mod;
    }
};

int main() { _
    string s,t;
    ll k;
    cin >> s >> t >> k;

    Hash h(s,1'000'000'007,27);
    Hash h2(s,1'000'000'009,27);
    vector<pair<ll,ll>> v;
    ll qtd;

    for(int i=0;i<s.size();i++) {
        qtd=0;
        for(int j=i;j<s.size();j++) {
            if(t[s[j]-'a']=='0') {
                qtd++;
                if(qtd>k) break;
            }

            v.push_back({h.get(i,j),h2.get(i,j)});
        }
    }

    ll ans=!v.empty();
    sort(v.begin(),v.end());
    for(int i=1;i<v.size();i++) if(v[i]!=v[i-1]) ans++;
    cout << ans << '\n';

    return 0;
}
