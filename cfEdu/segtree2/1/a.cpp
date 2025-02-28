#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void set(vector<ll> &st, ll pos, ll l, ll r, ll lq, ll rq, ll v) {
    if(rq<l or r<lq) return;
    if(lq<=l and r<=rq) {
        st[pos]+=v;
        return;
    }

    ll m = (l+r)>>1;
    ::set(st,2*pos+1,l,m,lq,rq,v);
    ::set(st,2*pos+2,m+1,r,lq,rq,v);
}

ll get(vector<ll> &st, ll pos, ll l, ll r, ll i) {
    if(i<l or r<i) return 0LL;
    if(l==r) return st[pos];

    ll m = (l+r)>>1;
    return st[pos]+get(st,2*pos+1,l,m,i)+get(st,2*pos+2,m+1,r,i);
}

int main() { _
    ll n,m,op,a,b,c;
    cin >> n >> m;

    vector<ll> st(n<<2,0LL);

    while(m--) {
        cin >> op >> a;

        if(op==1) {
            cin >> b >> c;
            b--;
            ::set(st,0,0,n-1,a,b,c);
        } else cout << get(st,0,0,n-1,a) << '\n';
    }

    return 0;
}
