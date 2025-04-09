#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

ll minI(vector<ll> &v, ll i) {
    ll a=v[i];
    if(a==1) return 0;
    ll j=i;
    for(i++;i<v.size();i++) {
        a=gcd(a,v[i]);
        if(a==1) return i-j; 
    }
    return -1;
}

ll sum(vector<ll> v, ll i, ll j) {
    ll r=0;
    for(ll x=i+1;x<v.size();x++) v[x] = gcd(v[x],v[x-1]),r++;
    for(ll i:v) if(i>1) r++;
    return r;
}

int main() { _
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll &i:v) cin >> i;

    if(minI(v,0)==-1) {
        cout << "-1\n";
        return 0;
    }

    ll min = LLONG_MAX;
    for(ll i=0;i<n;i++) {
        ll s = minI(v,i);
        if(s==-1) break;
        min = ::min(min,sum(v,i,i+s));
    }
    
    cout << min << '\n';
    return 0;
}
