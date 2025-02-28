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
    vector<int> a(n),b(n);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    int ans=0;
    for(int i=0;i<n;i++) {
        int m=INT_MAX;
        for(int j=0;j<n;j++) m=min(m,abs(a[j]-b[(i+j)%n]));
        ans=max(ans,m);
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
