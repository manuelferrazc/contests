#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

template<int MOD> struct str_hash {
    static int P;
    vector<ll> h,p;
    str_hash(string s) :h(s.size()), p(s.size()) {
        p[0] = 1, h[0] = s[0];
        for(int i=1;i<s.size();i++) p[i] = p[i-1]*P%MOD,h[i] = (h[i-1]*P+s[i])%MOD;
    }
    ll operator()(int l, int r) {
        ll hash = h[r]-(l?h[l-1]*p[r-l+1]%MOD : 0);
        return hash<0?hash+MOD:hash;
    }
};
template<int MOD> int str_hash<MOD>::P = uniform(256,MOD-1);

int main() { _
    string s;
    cin >> s;
    int n = s.size();

    str_hash<1'000'000'007> h1(s);
    str_hash<1'000'000'009> h2(s);

    for(int sz=1;sz<=n;sz++) {
        bool ok = true;
        pair p(h1(0,sz-1),h2(0,sz-1));
        for(int i=sz;i<n;i+=sz) {
            if(i+sz>=n) {
                pair p2(h1(i,n-1),h2(i,n-1));
                int size2 = n-i;
                if(p2!=pair(h1(0,size2-1),h2(0,size2-1))) ok = false;
            } else if(p!=pair(h1(i,i+sz-1),h2(i,i+sz-1))) {
                ok = false;
                break;
            }
        }
        if(ok) cout << sz << ' ';
    }

    cout << '\n';

    return 0;
}
