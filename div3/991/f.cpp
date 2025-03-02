#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void build(vector<ll> &seg, ll a, ll b, ll pos, vector<ll> &v, int op) {
    if(a==b) {
        seg[pos] = v[a];
        return;
    }

    int m = (a+b)/2;
    build(seg,a,m,2*pos+1,v,op);
    build(seg,m+1,b,2*pos+2,v,op);
    if(op==1) seg[pos] = min(seg[2*pos+1],seg[2*pos+2]);
    else if(op==2) seg[pos] = max(seg[2*pos+1],seg[2*pos+2]);
    else seg[pos] = gcd(seg[2*pos+1],seg[2*pos+2]);
}

ll get(vector<ll> &seg,ll a, ll b, ll l, ll r, ll pos, int op) {
    if(l<=a and b<=r) return seg[pos];
    if(b<l or r<a) return op==1 ? LLONG_MAX : 0;
    
    int m = (a+b)/2;
    return op==1 ? min(get(seg,a,m,l,r,2*pos+1,op),get(seg,m+1,b,l,r,2*pos+2,op))
                 : (op==2 ? max(get(seg,a,m,l,r,2*pos+1,op),get(seg,m+1,b,l,r,2*pos+2,op))
                          : gcd(get(seg,a,m,l,r,2*pos+1,op),get(seg,m+1,b,l,r,2*pos+2,op)));
}

void solve() {
    ll n,q,l,r;
    cin >> n >> q;

    vector<ll> mi(n<<2),ma(n<<2), g(n<<2),v(n),aux;
    for(ll i=0;i<n;i++) cin >> v[i];
    for(ll i=0;i<n-1;i++) aux.push_back(abs(v[i]-v[i+1]));

    if(aux.size()) build(g,0,n-2,0,aux,0);
    build(mi,0,n-1,0,v,1);
    build(ma,0,n-1,0,v,2);

    while(q--) {
        cin >> l >> r;
        l--;
        r--;
        if(get(mi,0,n-1,l,r,0,1)==get(ma,0,n-1,l,r,0,2)) cout << 0 << ' ';
        else cout << get(g,0,n-2,l,r-1,0,0) << ' ';
    }

    cout << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
