#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    ll n,s=0;
    cin >> n;

    vector<ll> v(n);
    for(ll &i:v) cin >> i;
    sort(v.begin(),v.end());

    for(ll i=0;i<n;i++) {
        if(v[i]>s+1) {
            cout << s+1 << '\n';
            return 0;
        }
        s+=v[i];
    }

    cout << s+1 << '\n';

    return 0;
}
