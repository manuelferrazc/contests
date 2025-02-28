#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct A {
    ll time;
    ll lim;
    ll rest;
};

bool count(vector<A> &v, ll t, ll b) {
    for(auto &p:v) {
        ll durc = p.lim*p.time+p.rest;
        ll qtdc=t/durc;
        b-=qtdc*p.lim;
        auto x = t%durc;
        x=min(x,p.time*p.lim);
        b-=x/p.time;
        if(b<=0) return true;
    }
    return false;
}

vector<ll> count2(vector<A> &v, ll t, ll b) {
    vector<ll> r(v.size(),0);

    for(ull i=0;i<v.size();i++) {
        ll durc = v[i].lim*v[i].time+v[i].rest;
        ll qtdc=t/durc;
        ll qtd = qtdc*v[i].lim + (min(t-qtdc*durc,v[i].lim*v[i].time))/v[i].time;
        r[i] = min(b,qtd);
        b-=qtd;
        if(b<=0) break;
    }
    return r;
}

int main() { _
    ll n,qtd;
    cin >> qtd >> n;
    if(qtd==0) {
        cout << "0\n";
        for(int i=0;i<n;i++) cout << 0 << ' ';
        cout << '\n';
        return 0;
    }

    vector<A> v(n);
    for(auto &i:v) cin >> i.time >> i.lim >> i.rest;

    ll l = 1,r=1e10, ans=LLONG_MAX;

    while(l<=r) {
        ll m = (l+r)>>1;
        if(count(v,m,qtd)) {
            ans = min(ans,m);
            r=m-1;
        } else l=m+1;
    }

    cout << ans << '\n';
    auto vt = count2(v,ans,qtd);
    for(auto i:vt) cout << i << ' ';
    cout << '\n';

    return 0;
}
