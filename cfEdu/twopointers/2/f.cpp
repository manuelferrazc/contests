#include <bits/stdc++.h>

using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

typedef long long ll;
typedef unsigned long long ull;

ll build(vector<ll> &st, vector<ll> &v, ll pos, ll l, ll r, bool min) {
    if(l==r) return st[pos] = v[l];

    ll m = (l+r)>>1, m1 = build(st,v,2*pos+1,l,m,min), m2 = build(st,v,2*pos+2,m+1,r,min);
    return st[pos] = min ? ::min(m1,m2) : max(m1,m2);
}

ll get(vector<ll> &st, ll pos, ll l, ll r, ll lq, ll rq, bool min) {
    if(rq<l or r<lq) return min?LLONG_MAX:LLONG_MIN;
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1;
    ll m1=get(st,2*pos+1,l,m,lq,rq,min), m2=get(st,2*pos+2,m+1,r,lq,rq,min);
    return min ? ::min(m1,m2) : max(m1,m2);
}

int main() { _
    ll n,k;
    cin >> n >> k;
    vector<ll> v(n), stmin(n<<2), stmax(n<<2);
    for(auto &i:v) cin >> i;

    build(stmin,v,0,0,n-1,true);
    build(stmax,v,0,0,n-1,false);

    ll ans=0,l=0,r=-1;

    while(r<n) {
        if(l>r) r++;
        else {
            ll mi = get(stmin,0,0,n-1,l,r,true);
            ll ma = get(stmax,0,0,n-1,l,r,false);
            if(ma-mi<=k) {
                ans+=r-l+1;
                r++;
            } else l++;
        }
    }

    cout << ans << '\n';

    return 0;
}
