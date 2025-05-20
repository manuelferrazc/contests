#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> v,sp,st;

ll build(ll pos, ll l, ll r) {
    if(l==r) return st[pos] = sp[l];

    ll m = (l+r)>>1,ls = 2*pos+1;
    return st[pos] = max(build(ls,l,m),build(ls+1,m+1,r));
}

ll get(ll pos, ll l, ll r, ll lq, ll rq) {
    if(lq<=l and r<=rq) return st[pos];
    if(r<lq or rq<l) return LLONG_MIN;

    ll m = (l+r)>>1,ls = 2*pos+1;
    return max(get(ls,l,m,lq,rq),get(ls+1,m+1,r,lq,rq));
}

int main() { _
    ll n,a,b;
    cin >> n >> a >> b;
    v.resize(n);
    sp.resize(n);
    st.resize(n<<2);
    cin >> v[0];
    sp[0] = v[0];

    for(ll i=1;i<n;i++) {
        cin >> v[i];
        sp[i] = v[i]+sp[i-1];
    }

    build(0,0,n-1);

    ll ans = get(0,0,n-1,a-1,b-1);
    for(ll i=1;a-1+i<n;i++) {
        ans = max(ans,get(0,0,n-1,a-1+i,min(b-1+i,n-1))-sp[i-1]);
    }

    cout << ans << '\n';

    return 0;
}
