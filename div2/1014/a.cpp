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
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());
    int ans=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) if(v[j]!=v[i]+1) ans=max(ans,gcd(v[j]+(v[j]-v[i]-1),v[i]+(v[j]-v[i]-1)));
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
