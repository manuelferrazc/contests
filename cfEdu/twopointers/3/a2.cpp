#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,p;
    cin >> n >> p;
    vector<ll> v(n);
    ll soma = 0; 
    for(auto &i:v) {
        cin >> i;
        soma+=i;
    }

    ll s = (p/soma)*n,b=1;
    p = p%soma;

    if(not p) {
        cout << "1 " << s << '\n';
        return 0;
    }

    ll min=LLONG_MAX;
    for(ll i=0;i<n;i++) {
        ll so=0,j = 0;
        for(;j<n and so<p;j++) so+=v[(i+j)%n];
        if(j<min and so>=p) {
            min = j;
            b=i+1;
        }
    }

    cout << b << ' ' << s+min << '\n';

    return 0;
}
