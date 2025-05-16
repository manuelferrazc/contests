#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,m,k,ans=0,i=0,j=0;

    cin >> n >> m >> k;
    vector<ll> r(n),ap(m);

    for(ll &x:r) cin >> x;
    for(ll &x:ap) cin >> x;
    sort(r.begin(),r.end());
    sort(ap.begin(),ap.end());

    while(i<n and j<m) {
        if(r[i]-k<=ap[j] and r[i]+k>=ap[j]) {
            ans++;
            i++;
            j++;
        } else if(r[i]-k>=ap[j]) j++;
        else i++;
    }

    cout << ans << '\n';

    return 0;
}
