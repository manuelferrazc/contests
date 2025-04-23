#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll add(vector<ll> &v, ll qtd, ll x,ll l=0) {
    ll n = v.size(),i;
    for(i=0;i<n and qtd;i++) {
        if(v[(i+l)%n]==-1 and (i==0 or v[(i-1+n+l)%n]!=x)) {
            v[(i+l)%n] = x;
            qtd--;
        }
    }

    if(v[l]==v[(l+n-1)%n]) {
        v[(l+n-1)%n]=-1;
        return (l+n-1)%n;
    }
    return i==n? (i+l+1)%n : (l+i)%n;
}

int main() { _
    ll n, m;
    cin >> n >> m;
    vector<ll> v(m),ans(n,-1);
    for(ll &i:v) cin >> i;

    set<pair<ll,ll>> s;
    for(ll i=0;i<m;i++) s.insert(make_pair(min(v[i],n/2),i+1));
    
    ll l=0;
    for(auto it = s.rbegin();it!=s.rend();it++) {
        l = add(ans,(*it).ff,(*it).ss,l);
    }

    for(ll i:ans) {
        if(i==-1) {
            cout << -1 << '\n';
            return 0;
        }
    }
    for(ll i:ans) cout << i << ' ';
    cout << '\n';
    return 0;
}
