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
    for(int &i:a) cin >> i;
    for(int &i:b) cin >> i;

    int ans=1;
    for(int i=0;i<n;i++) if(a[i]>b[i]) ans+=a[i]-b[i];

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
