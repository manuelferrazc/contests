#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;
    
    vector<ll> v(2*n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    ll sufo=0,sufe=0;
    for(ll i=0;i<(ll)v.size();i+=2) sufe+=v[i];
    for(ll i=1;i<(ll)v.size();i+=2) sufo+=v[i];

    ll preo=0,pree=0;
    for(ll i=0;i<(n<<1);i++) {
        if((i+1)&1) {
            ll x=sufe-sufo-preo+pree;
            auto it = lower_bound(v.begin(),v.end(),x);
            if(x>0LL and (it==v.end() or *it!=x)) {
                for(ll j=0;j<i;j++) cout << v[j] << ' ';
                cout << x << ' ';
                for(ll j=i;j<(n<<1);j++) cout << v[j] << ' ';
                cout << '\n';
                return;
            }
            sufe-=v[i];
            preo+=v[i];
        } else {
            ll x=sufo-sufe+preo-pree;
            auto it = lower_bound(v.begin(),v.end(),x);
            if(x>0LL and (it==v.end() or *it!=x)) {
                for(ll j=0;j<i;j++) cout << v[j] << ' ';
                cout << x << ' ';
                for(ll j=i;j<(n<<1);j++) cout << v[j] << ' ';
                cout << '\n';
                return;
            }
            sufo-=v[i];
            pree+=v[i];
        }
    }
}

int main() { _
    ll t;
    cin >> t;
    while(t--) solve();
    return 0;
}
