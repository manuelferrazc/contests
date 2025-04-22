#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll m = 1'000'000'007ll;

ll fexp(ll n, ll e) {
    if(e==0) return 1;
    if(e==1) return n;

    ll r = fexp(n,e>>1)%m;
    r = (r*r)%m;
    if(e&1) r = (r*n)%m;

    return r;
}

ll get(vector<ll> &p, ll a) {
    return p[a] = (p[a]==a? a : get(p,p[a]));
}

void uniom(vector<ll> &p, vector<ll> &s, ll a, ll b) {
    a = get(p,a);
    b = get(p,b);
    if(a==b) return;

    if(s[a]<s[b]) swap(a,b);

    s[a]+=s[b];
    p[b] = a;
}

int main() { _
    ll n,k;
    cin >> n >> k;

    // vector<vector<pair<ll,bool>>> adj(n);
    vector<pair<ll,ll>> black;

    vector<ll> p(n), s(n,1);
    for(ll i=0;i<n;i++) p[i] = i;

    for(ll nettinho = 1;nettinho<n;nettinho++) {
        ll a,b;
        bool c;
        cin >> a >> b >> c;
        a--;
        b--;
        // adj[a].push_back(make_pair({b,c}));
        // adj[b].push_back(make_pair({a,c}));
        if(c) black.push_back(make_pair(a,b));
        else uniom(p,s,a,b);
    }


    ll ans = 0;

    for(pair<ll,ll> e:black) {
        ll ra = get(p,e.ff), rb = get(p,e.ss);
        ll sa = s[ra],sb = s[rb];

        uniom(p,s,ra,rb);
        ra = get(p,ra);
        ans+=fexp(s[ra],k);
        ans%=m;
        ans = (ans+m-fexp(sa,k))%m;
        ans = (ans+m-fexp(sb,k))%m;
    }

    cout << ans << '\n';
    return 0;
}
