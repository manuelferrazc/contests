#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll n,m;
set<pair<ll,ll>> s;

bool test(ll x) {
    for(pair<ll,ll> p:s) {
        ll a = (p.ff+x)%n;
        ll b = (p.ss+x)%n;
        if(not s.count(make_pair(min(a,b),max(a,b))))return false;
    }
    return true;
}

int main() { _
    cin >> n >> m;
    vector<ll> d;
    for(ll i=1;i<n;i++) if(n%i==0) d.push_back(i);

    for(ll i=0;i<m;i++) {
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        
        s.insert(make_pair(min(b,a),max(a,b)));
    }

    for(ll div:d) {
        if(test(div)) {
            cout << "Yes\n";
            return 0;
        }
    }

    cout << "No\n";

    return 0;
}
