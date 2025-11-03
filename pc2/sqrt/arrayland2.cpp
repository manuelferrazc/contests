#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;
    // cout << n << '\n';
    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];
    int q;
    cin >> q;

    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;

        int ans = INT_MAX;

        for(int i=l;i<r;i++) {
            for(int j=i+1;j<=r;j++) {
                ans = min(ans,abs(v[i]-v[j]));
            }
        }

        cout << ans << '\n';
    }
    return 0;
}
