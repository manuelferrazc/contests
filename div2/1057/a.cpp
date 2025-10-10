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

    int v[100];
    for(int i=0;i<100;i++) v[i] = 0;

    int ans;
    while(n--) {
        cin >> ans;
        v[ans-1] = 1;
    }

    ans=0;
    for(int i=0;i<100;i++) if(v[i]) ans++;
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
