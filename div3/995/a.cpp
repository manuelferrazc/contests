#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n),b(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    int ans=0;
    for(int i=1;i<n;i++) ans+=max(0,a[i-1]-b[i]);
    ans+=a.back();
    cout << ans << '\n';

}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
