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

    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    if(n==1) {
        cout << v[0] << '\n';
        return;
    }
    // if(n!=9) return;
    ll s=0;
    for(ll i=0;i<n;i++) {
        if(i&1) s-=v[i];
        else s+=v[i];
    }

    ll so = s;

    s = max(s,so+(n&1?n:n-1)-1);

    auto v2 = v;
    // for(int i=0;i<n;i+=2) v2[i]+=i;
    // for(int i=1;i<n;i+=2) v2[i]-=i;

    ll m1 = 1, m0 = 0;

    s = max(s,so+1-v[0]*2+v[1]*2);
    // cout << s << '\n';
    for(ll i=2;i<n;i++) {
        // cout << i << ' ';
        if(i&1) {
            if(v[i]*2-i>v[m1]*2-m1) m1 = i;

            // cout << "m1 = " << m1 << '\n';

            // operacao j,i, com i em negativo
            s = max(s,so+v[i]*2-2*v[m0]+(i-m0));
            // cout << i << ' ' << m1 << ' ' << m0 << "sla kk f\n";
            // if(s==289) {
            //     return;
            // }
        } else {
            
            if(v2[i]*2+i<v2[m0]*2+m0) m0 = i;
            // cout << "m0 = " << m0 << '\n';
            // operacao j,i, com i em positivo
            s = max(s,so-v[i]*2+2*v[m1]+(i-m1));
        }
        // cout << s << '\n';
        // cout << i << ' ' << m1 << ' ' << m0 << " sla kk f ";
    }

    // s=max(s,so+v[m1]-v[m0]-v2[m1]+v2[m0]);

    // for(int i=0;i<n;i+=2) v2[i]-=i;
    // for(int i=1;i<n;i+=2) v2[i]+=i;

    // for(int i=0;i<n;i+=2) v2[i]-=i;
    // for(int i=1;i<n;i+=2) v2[i]+=i;

    // m1 = 0, m0 = 1;
    // // ll m1sla, m0sla;

    // for(ll i=2;i<n;i++) {
    //     if(i&1) {
    //         if(v2[i]>v2[m1]) m1 = i;
    //     } else if(v2[i]<v2[m0]) m0 = i;
    // }

    // if(m1>m0)s=max(s,so+v[m1]-v[m0]-v2[m1]+v2[m0]);

    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
