#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<ll,ll> build(vector<pair<ll,ll>> &st, vector<ll> &dif, ll pos, ll l, ll r) {
    if(l==r) return st[pos] = {dif[l],l};

    ll m = (l+r)>>1, ls = 2*pos+1;
    return st[pos] = min(build(st,dif,ls,l,m),build(st,dif,ls+1,m+1,r));
}

pair<ll,ll> get(vector<pair<ll,ll>> &st, ll pos, ll l, ll r, ll lq, ll rq) {
    if(r<lq or rq<l) return make_pair(LLONG_MAX,-1LL);
    if(lq<=l and r<=rq) return st[pos];

    ll m = (l+r)>>1, ls = 2*pos+1;
    return min(get(st,ls,l,m,lq,rq),get(st,ls+1,m+1,r,lq,rq));
}

void solve() {
    ll n,k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;

    for(ll i=0;i<n;i++) if(a[i]>b[i]) swap(a[i],b[i]);// a[i] é o minimo
    
    vector<pair<ll,ll>> v(n);
    for(ll i=0;i<n;i++) 
        v[i] = make_pair(a[i],b[i]);
    
    sort(v.begin(),v.end());

    ll x=-1,y=-1, ans = LLONG_MAX;
    vector<ll> dif(n);
    vector<pair<ll,ll>> st(4*n);
    for(ll i=0;i<n;i++) dif[i] = v[i].ss-v[i].ff;
    build(st,dif,0,0,n-1);
    for(ll i=0;i<n;i++) {
        auto it = upper_bound(v.begin(),v.end(),make_pair(v[i].ss,-1LL));

        if(it==v.end()) {
            x=0;
            for(int j=0;j<n;j++) x+=b[j]-a[j];
            cout << "sla\n";
            cout << x << '\n';
            return;
        }

        ll id = it-v.begin();
        auto p2 = get(st,0,0,n-1,id,n-1);
        auto p = p2.ss;

        ll act = v[i].ff+v[i].ss-v[p].ff-v[p].ss;
        act = -act;
        cout << act << "act << '\n'";
        if(act<ans) {
            x = i;
            y = p;
            ans = act;
        }
    }

    if(x!=-1)ans = v[y].ff+v[y].ss-v[x].ff-v[x].ss;
    for(ll i=0;i<n;i++) {
        if(i==x or i==y) continue;
        ans+=v[i].ss-v[i].ff;
    }

    cout << ans << '\n';
}

int main() { _
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
