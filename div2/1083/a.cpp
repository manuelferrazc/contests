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

    int p[n+1];
    for(int i=1;i<=n;i++) cin >> p[i];
    for(int i=1;i<=n;i++) if(p[i]==n) {
        swap(p[i],p[1]);
        break;
    }

    for(int i=1;i<=n;i++) cout << p[i] << ' ';
    cout << '\n';

    
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
