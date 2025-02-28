#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,s;
    cin >> n >> s;
    vector<int> w(n), c(n);
    for(auto &i:w) cin >> i;
    for(auto &i:c) cin >> i;

    ll ans=(s>=w[0]?c[0]:0),l=0,r=0,we=w[0],pr=c[0];

    while(r<n) {
        if(we<=s) {
            ans=max(ans,pr);
            r++;
            if(r==n) break;
            we+=w[r];
            pr+=c[r];
        } else {
            we-=w[l];
            pr-=c[l++];
        }
    }

    cout << ans << '\n';

    return 0;
}
