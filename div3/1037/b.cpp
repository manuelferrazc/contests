#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k,ans=0;
    cin >> n >> k;
    vector<int>v (n);
    for(int &i:v) cin >> i;

    int b=0;
    for(int i=0;i<n;i++) {
        if(i<b) continue;
        if(v[i]) b=i+1;
        else {
            if(b+k-1==i) {
                ans++;
                b=i+2;
            }
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
