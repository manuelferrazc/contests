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

    for(ll i=0;i<n;i++) v.push_back(v[i]);
    v.push_back(0);

    ll l=0,r=-1,sp=0,sg=LLONG_MAX;
    while(l<=n and r<(n<<1)) {
        if(l>r) sp+=v[++r];
        else if(sp>=p) {
            if(r-l+1<sg) {
                b = l+1;
                sg = r-l+1;
            }
            sp-=v[l++];
        } else sp+=v[++r];
    }

    cout << b << ' ' << s+sg << '\n';

    return 0;
}
