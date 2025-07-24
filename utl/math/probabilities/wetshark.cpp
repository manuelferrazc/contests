#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,p;
    cin >> n >> p;

    double ans=0;

    vector<pair<ll,ll>> v(n);
    for(auto &[a,b]:v) cin >> a >> b;

    vector<double> vok(n+1);
    for(int i=0;i<n;i++) vok[i] = (v[i].ss/p-(v[i].ff-1)/p)/(v[i].ss-v[i].ff+1.0);
    
    vok[n] = vok[0];
    for(int i=0;i<n;i++) {
        ans+=vok[i];
        ans+=(1-vok[i])*vok[i+1];
    }

    cout << fixed << setprecision(10) << ans*2000 << '\n';

    return 0;
}
