#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

map<ll,ll> m;
string a, b;

bool test(ll x) {
    string aux;
    for(int i=0;i<a.size();i++) if(m[i]>=x) aux.push_back(a[i]);
    ll a=0;
    for(ll i=0;i<aux.size();i++) {
        if(aux[i]==b[a]) a++;
        if(a>=b.size()) return true;
    }
    return false;
}

int main() { _
    cin >> a >> b;
    for(int i=0;i<a.size();i++) {
        int x;
        cin >> x;
        m[x-1] = i;
    }

    ll ans=0,l=0,r=a.size();
    while(l<=r) {
        ll m = (l+r)>>1;
        if(test(m)) {
            ans=max(ans,m);
            l=m+1;
        } else r=m-1;
    }
    cout << ans << '\n';

    return 0;
}
