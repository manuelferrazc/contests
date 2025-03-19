#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef tree<
pair<ll,ll>,
null_type,
less<pair<ll,ll>>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

vector<ll> st1, sts,stm, vs;

ll build1(ll pos, ll l, ll r) {
    if(l==r) return st1[pos]=1;
    ll m=(l+r)/2;
    return st1[pos]=build1(2*pos+1,l,m)+build1(2*pos+2,m+1,r);
}

ll builds(ll pos, ll l, ll r) {
    if(l==r) return sts[pos] = vs[l];
    ll m = (l+r)/2;
    return sts[pos]=builds(2*pos+1,l,m)+builds(2*pos+2,m+1,r);
}

ll buildm(ll pos, ll l, ll r) {
    if(l==r) return stm[pos] = vs[l];
    ll m = (l+r)/2;
    return stm[pos]=max(buildm(2*pos+1,l,m),buildm(2*pos+2,m+1,r));
}

void zera(ll pos, ll l, ll r, ll i) {
    if(i<l or r<i) return;
    if(l==r) {
        stm[pos] = sts[pos] = st1[pos] = 0;
        return;
    }

    ll m = (l+r)>>1, ls = 2*pos+1;
    zera(ls,l,m,i);
    zera(ls+1,m+1,r,i);
    sts[pos] = sts[ls] + sts[ls+1];
    st1[pos] = st1[ls] + st1[ls+1];
    stm[pos] = max(stm[ls],stm[ls+1]);
}

ll sum(ll pos, ll l, ll r, ll lq, ll rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return sts[pos];
    ll m = (l+r)>>1;
    return sum(2*pos+1,l,m,lq,rq)+sum(2*pos+2,m+1,r,lq,rq);
}

ll sum1(ll pos, ll l, ll r, ll lq, ll rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st1[pos];
    ll m = (l+r)>>1;
    return sum1(2*pos+1,l,m,lq,rq)+sum1(2*pos+2,m+1,r,lq,rq);
}

ll Max(ll pos, ll l, ll r, ll lq, ll rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return stm[pos];
    ll m = (l+r)>>1;
    return max(Max(2*pos+1,l,m,lq,rq),Max(2*pos+2,m+1,r,lq,rq));
}

ll bb(ll x, ll n) {
    ll l=1,r = n-1;
    ll ans=LLONG_MAX;
    while(l<=r) {
        ll m = (l+r)>>1;
        if((x+sum(0,0,n-1,0,m-1)>=Max(0,0,n-1,m,n-1))) {
            ans = m;
            r = m-1;
        } else l = m+1;
    }

    return sum1(0,0,n-1,0,ans-1);
}

void solve() {
    ll n,c,m=0,sp=0;
    cin >> n >> c;
    vector<ll> v(n);
    vs.resize(n);
    for(auto &i:v) cin >> i;
    v[0]+=c;

    for(ll i=0;i<n;i++) {
        if(v[i]>v[m]) m=i;
        vs[i] = v[i];
    }

    sort(vs.rbegin(),vs.rend());
    map<ll,set<ll>> ma;
    for(ll i=0;i<n;i++) ma[vs[i]].insert(i);
    sts.resize(n<<2);
    st1.resize(n<<2);
    stm.resize(n<<2);
    build1(0,0,n-1);
    builds(0,0,n-1);
    buildm(0,0,n-1);
    
    for(ll i=0;i<n;i++) {
        ll x = *ma[v[i]].begin();
        zera(0,0,n-1,x);
        ma[v[i]].erase(ma.at(v[i]).begin());
        
        sp+=v[i];
        if(i==m) cout << 0 << ' ';
        else if(sp>=Max(0,0,n-1,0,n-1)) cout << i << ' ';
        else cout << i+bb(sp,n) << ' ';
    }
    cout << '\n';
}

int main() {// _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
