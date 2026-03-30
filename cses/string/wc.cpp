#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define m1 1'000'000'007
#define m2 1'000'000'009

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
    uniform_int_distribution<int> uid(l,r);
    return uid(rng);
}

const int mod = 1'000'000'007;


template<int MOD> struct str_hash {
    static int P;
    vector<ll> h,p;
    str_hash(string s) : h(s.size()), p(s.size()) {
        p[0] = 1,h[0] = s[0];
        for(int i=1;i<s.size();i++) p[i] = p[i-1]*P%MOD, h[i] = (h[i-1]*P+s[i])%MOD;
    }

    ll operator()(int l, int r) {
        ll hh = h[r]-(l ? h[l-1]*p[r-l+1]%MOD : 0);
        return hh<0? hh+MOD : hh;
    }
};

template<int MOD> int str_hash<MOD>::P = uniform(256,MOD-1);


int main() { _
    map<int,vector<pair<ll,ll>>> dict;

    string s;
    int k;
    cin >> s >> k;

    while(k--) {
        string t;
        cin >> t;

        str_hash<m1> h1(t);
        str_hash<m2> h2(t);

        dict[t.size()].push_back(pair(
            h1(0,t.size()-1),
            h2(0,t.size()-1)
        ));
    }

    for(auto it = dict.begin();it!=dict.end();it++) sort(it->ss.begin(),it->ss.end());
    
    ll dp[s.size()+1];
    dp[0] = 1;

    str_hash<m1> h1(s);
    str_hash<m2> h2(s);

    for(int i=1;i<=(int)s.size();i++) {
        dp[i] = 0;

        for(int st = 0;st<i;st++) { // substring s[st...i-1]
            int sz = i - st;

            pair<ll,ll> tg(h1(st,i-1),h2(st,i-1));

            if(dict.count(sz)==0ull) continue;
            vector<pair<ll,ll>> &v = dict[sz];

            auto it = lower_bound(v.begin(),v.end(),tg);
            if(it!=v.end() and *it==tg) dp[i]+=dp[st];
        }

        dp[i]%=mod;
    }

    cout << dp[s.size()] << '\n';

    return 0;
}
