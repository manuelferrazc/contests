#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int t=v[0];
    for(int i=1;i<n;i++) t&=v[i];
    
    if(t) {
        cout << "1\n";
        return;
    }

    t=-1;
    int ans=0;
    for(int i=0;i<n;i++) {
        t&=v[i];
        if(t==0) {
            t=-1;
            ans++;
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
