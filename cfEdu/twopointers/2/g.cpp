#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> st,v;

ll build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = v[l];

    ll m=(l+r)>>1, m1=build(2*pos+1,l,m), m2=build(2*pos+2,m+1,r);
    return st[pos] = gcd(m1,m2);
}

ll get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1;
    ll m1=get(2*pos+1,l,m,lq,rq), m2=get(2*pos+2,m+1,r,lq,rq);
    return gcd(m1,m2);
}

int main() { _
    ll n;
    cin >> n;
    
    v.resize(n);
    st.resize(n<<2);
    for(auto &i:v) cin >> i;
    build(0,0,n-1);

    ll ans=LLONG_MAX, l=0,r=0;
    while(r<n) {
        if(l>r) r++;
        else if(get(0,0,n-1,l,r)==1) {
            ans=min(ans,r-l+1);
            l++;
        } else r++;
    }
    
    if(ans==LLONG_MAX) cout << "-1\n";
    else cout << ans << '\n';

    return 0;
}
