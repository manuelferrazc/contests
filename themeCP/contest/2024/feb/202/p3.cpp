#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,mod;
vector<ll> st,v;

ll build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = v[l]%mod;
    ll m = (l+r)>>1;
    st[pos] = (build(2*pos+1,l,m)*build(2*pos+2,m+1,r))%mod;
    return st[pos];
}

ll get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return 1LL;
    if(lq<=l and r<=rq) return st[pos];

    ll m=(l+r)>>1;
    return (get(2*pos+1,l,m,lq,rq)*get(2*pos+2,m+1,r,lq,rq))%mod;
}

void solve() {
    cin >> n >> mod;
    st.resize(n<<2);
    v.resize(n);

    for(auto &i:v) cin >> i;
    build(0,0,n-1);
    string s;
    cin >> s;

    ll l=0,r=n-1;
    for(auto c:s) {
        cout << get(0,0,n-1,l,r) << ' ';
        if(c=='L') l++;
        else r--;
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
