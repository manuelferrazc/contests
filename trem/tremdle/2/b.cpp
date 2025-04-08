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
    int ans=0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        ans+=a-1;
    }
    if(ans&1) cout << "errorgorn\n";
    else cout << "maomao90\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
