#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Hash {
    ll mod;
    vector<ll> p,h;

    struct SegTree {
        vector<ll> st;


        ll build(string &s, ll pos, ll l, ll r) {
            if(l==r) return st[pos] = s[l];

            ll m = (l+r)>>1,ls = 2*pos+1;
            return st[pos] = (build(s,ls,l,m)*p[r-m]+build(s,ls+1,m+1,r))%mod;
        }

        SegTree(string &s) {
            st.resize(s.size()*4,0);

            build(s,0,0,s.size()-1);
        }
    };

    SegTree st;
};

int main() { _
    return 0;
}
