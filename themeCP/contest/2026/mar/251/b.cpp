#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,c;
    cin >> n >> c;

    ll v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    ll l = 1;
    ll r = 2'000'000'000;

    while(l<=r) {
        ll w = (l+r)>>1;

        ll sum = 0;
        for(int i=0;i<n;i++) {
            sum+=(v[i]+2*w)*(v[i]+2*w);
            if(sum>c) break;
        }

        if(sum<c) l=w+1;
        else if(sum>c) r = w-1;
        else {
            cout << w << '\n';
            return;
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
