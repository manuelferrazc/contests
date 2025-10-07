#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
const ll mod1 = 998244353, mod2 = 1000000007;
 
ll fexp(ll n, ll e, ll mod) {
    if(e==0) return 1;
    if(e==1) return n;
    
    ll r = fexp(n,e>>1,mod);
    r = r*r%mod;
    if(e&1) r = r*n%mod;
 
    return r;
}
 
int main() { _
    string s;
    cin >> s;
    const ll n = s.size();
 
    vector<ll> oc1;
    vector<pair<ll,ll>> oc;
    ll p=30,e1=1,e2=1;
    pair<ll,ll> x,y;
    x.ff = x.ss = 0;
    y.ff = y.ss = 0;
 
    e1 = e2 = 1;
 
    const ll inv1 = fexp(30,mod1-2,mod1);
    const ll inv2 = fexp(30,mod2-2,mod2);
 
    for(ll i=0;i<n-2;i++) {
        x.ff = (x.ff+(s[i]-'a'+1)*e1)%mod1;
        y.ff = (y.ff*p%mod1+(s[n-i-1]-'a'+1))%mod1;
        x.ss = (x.ss+(s[i]-'a'+1)*e2)%mod2;
        y.ss = (y.ss*p%mod2+(s[n-i-1]-'a'+1))%mod2;
 
        if(x==y) {
            oc1.push_back(i+1);
            oc.push_back(x);
        }
        e1 = e1*p%mod1;
        e2 = e2*p%mod2;
    }
    
    sort(oc1.rbegin(),oc1.rend());
    sort(oc.begin(),oc.end());
 
    for(ll m:oc1) {
        x.ff = x.ss = 0;
        e1 = e2 = 1;
        bool ok = false;
 
        for(ll i=1;i<=m;i++) {
            x.ff = (x.ff+(s[i]-'a'+1)*e1)%mod1;
            x.ss = (x.ss+(s[i]-'a'+1)*e2)%mod2;
 
            if(i!=m){
                e1 = e1*p%mod1;
                e2 = e2*p%mod2;
            }
        }
 
        auto it = lower_bound(oc.begin(),oc.end(),x);
        if(it!=oc.end() and *it==x) ok = true;
        else for(ll i=m+1;i<n-1;i++) {
            x.ff = (x.ff-(s[i-m]-'a'+1)+mod1)%mod1;
            x.ss = (x.ss-(s[i-m]-'a'+1)+mod2)%mod2;
 
            x.ff = x.ff*inv1%mod1;
            x.ss = x.ss*inv2%mod2;
 
            x.ff = (x.ff+(s[i]-'a'+1)*e1)%mod1;
            x.ss = (x.ss+(s[i]-'a'+1)*e2)%mod2;
 
            it = lower_bound(oc.begin(),oc.end(),x);
            if(it!=oc.end() and (*it)==x) {
                ok = true;
                break;
            }
        }
 
        if(ok) {
            cout << s.substr(0,m) << '\n';
            return 0;
        }
    }
 
    cout << "Just a legend\n";
 
    return 0;
} // sla qq isso faz kk