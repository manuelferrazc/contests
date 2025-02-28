#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> st;

ll set(ll pos, ll l, ll r, ll i, ll x) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = x;

    ll m=(l+r)>>1LL, ls = 2*pos+1;
    return st[pos] = min(::set(ls,l,m,i,x),::set(ls+1,m+1,r,i,x));
}

ll get(ll pos, ll l, ll r, ll lq, ll rq, ll p) {
    if(rq<l or r<lq or st[pos]>p) return 0;
    if(l==r) {
        if(st[pos]>p) return 0;
        st[pos]=LLONG_MAX;
        return 1;
    }

    ll m = (l+r)>>1,ls=2*pos+1;
    ll ret = get(ls,l,m,lq,rq,p)+get(ls+1,m+1,r,lq,rq,p);
    st[pos] = min(st[ls],st[ls+1]);
    return ret;
}

int main() { _
    ll n,m,op,a,b,c;
    cin >> n >> m;
    st.assign(n*4,LLONG_MAX);

    while(m--) {
        cin >> op >> a >> b;

        if(op==1) ::set(0,0,n-1,a,b);
        else {
            cin >> c;
            cout << get(0,0,n-1,a,b-1,c) << '\n';         
        }
    }
    return 0;
}
