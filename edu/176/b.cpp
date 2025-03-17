#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,k;

ll get(multiset<ll> &m, int qtd) {
    ll s=0;
    
    for(auto it = m.rbegin();qtd;it++,qtd--) {
        s+=*it;
    }
    return s;
}

ll count(multiset<ll> &b, multiset<ll> &a, int ii) {
    ll s=0;

    vector<ll> bs(1,0),as(1,0);
    int qtd=ii;
    for(auto it=b.rbegin();qtd;qtd--,it++) {
        bs.push_back(bs.back()+*it);
    }
    qtd=n-ii-1;
    for(auto it=a.rbegin();qtd;qtd--,it++) {
        
        as.push_back(as.back()+*it);
    }
    
    for(ll i=1;i<min(k,(ll)bs.size()-1);i++) {
        if(k-i>=as.size()) continue;
        s=max(s,bs[i]+as[k-i]);
    }
    return s;
}

void solve() {
    cin >> n >> k;
    vector<ll> v(n);
    for(auto &i:v) cin >> i;
    multiset<ll> a,b;
    for(auto &i:v) a.insert(i);
    a.erase(a.lower_bound(v[0]));
    ll s=v[0]+get(a,k);
    for(int i=1;i<n-1;i++) {
        b.insert(v[i-1]);
        a.erase(a.lower_bound(v[i]));
        s=max(s,count(b,a,i)+v[i]);
    }
    b.insert(v[n-2]);
    s=max(v[n-1]+get(b,k),s);
    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
