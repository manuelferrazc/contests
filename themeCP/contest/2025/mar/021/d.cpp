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
    if(n==1 or n==3) cout << -1 << '\n';
    else if(n&1) cout << string(n-5,'3')+"36366\n";
    else cout << string(n-2,'3')+string(2,'6') << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
