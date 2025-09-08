#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;

void operation(vector<ll> &v) {
    sort(v.begin(),v.end());
    set<ll> nt;
    for(ll i=0;i<=n+1;i++) nt.insert(i);
    vector<ll> qtd(n+1,0);

    for(ll i:v) {
        qtd[i]++;
        nt.erase(i);
    }

    for(ll &i:v) {
        if(qtd[i]==1) i = min(i,*nt.begin());
        else i = *nt.begin();
    }
}

ll soma(const vector<ll> &v) {
    ll r=0;
    for(ll i:v) r+=i;
    return r;
}

void solve() {
    cin >> n >> k;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    
    operation(v);
    ll s1 = soma(v);
    
    if(k==1) cout << s1 << '\n';
    else {
        operation(v);
        s1 = soma(v);
        operation(v);
        ll s2 = soma(v);
        
        k--;
        if(k&1) cout << s1 << '\n';
        else cout << s2 << '\n';
    }
        
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
