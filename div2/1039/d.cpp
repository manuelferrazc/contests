#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

pair<ll,ll> find(const vector<ll> &v, ll a, ll b) {
    pair<ll,ll> aux;
    aux.ff = aux.ss = a;

    ll act = a;
    for(ll i=a+1;i<=b;i++) {
        if(v[i-1]<v[i]) act = i;
        else {
            if(i-act+1>aux.ss-aux.ff+1) {
                aux.ff = act;
                aux.ss = i;
            }
        }
    }

    return aux;
}

vector<ll> sp(500'001);

ll gets(ll n) {
    ll si = (n+1)*n/2;
    ll sn = si*n;
    ll sq = sp[n];
    // cout << "n = " << n << ", r = " << si+sn-sq << '\n';
    return si+sn-sq;
}

ll calc(const vector<ll> &v, ll a, ll b) {
    if(a>b) return 0;
    if(a==b) return 1;
    auto p = find(v,a,b);

    ll ans = (p.ff-a)*(b-p.ss)*(p.ss-p.ff+1); // comecam antes e terninam dps
    // cout << p.ff << ' ' << p.ss << ' ';
    ans+=gets(p.ss-p.ff+1); // comecam e acabam aq
    
    if(p.ff!=a) {
        auto p2 = find(v,a,p.ff-1);
        ll s = p2.ss-p2.ff+1;

        ll x = p.ss;
        while(x-p.ff+1>=s) {
            
            ans+=(p.ff-a)*(x-p.ff+1);
            x--;
        }

        ans+=calc(v,a,x);
    }

    if(p.ss!=b) {
        auto p2 = find(v,p.ss+1,b);
        ll s = p2.ss-p2.ff+1;

        ll x = p.ff;

        while(p.ss-x+1>=s) {
            ans+=(b-p.ss)*(p.ss-x+1);
            x++;
        }
        
        ans+=calc(v,x,b);
    }
    cout << a << ' ' << b << ' ' << ans << '\n';
    cout << "max: " << p.ff << ' ' << p.ss << '\n';
    return ans;
}

void solve() {
    ll n;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    // cout << "max: " << find(v,0,n-1).ff << ' ' << find(v,0,n-1).ss << '\n';
    cout << calc(v,0,n-1) << '\n';
}

int main() { _
    sp[0] = 0;
    for(ll i=1;i<500001;i++) sp[i] = sp[i-1]+i*i;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
