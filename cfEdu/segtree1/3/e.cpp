#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<ll> st;

ll get(ll pos, ll l, ll r, ll x) {
    if(l==r) return st[pos];

    ll m = (l+r)>>1;
    if(x<=m) return st[pos]+get(2*pos+1,l,m,x);
    return st[pos]+get(2*pos+2,m+1,r,x);
}

void set(ll pos, ll l, ll r, ll lq, ll rq, ll v) {
    if(rq<l or r<lq) return;
    if(lq<=l and r<=rq) {
        st[pos]+=v;
        return;
    }

    ll m = (l+r)>>1;
    ::set(2*pos+1,l,m,lq,rq,v);
    ::set(2*pos+2,m+1,r,lq,rq,v);
}

int main() { _
    ll n,m,op,a,b;
    ll c;
    cin >> n >> m;
    st.assign(n<<2,0);

    while(m--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b >> c;
            ::set(0,0,n-1,a,b-1,c);
        } else cout << get(0,0,n-1,a) << '\n';
    }

    return 0;
}
