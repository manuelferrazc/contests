#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int a,b;
    cin >> a >> b;
    if((a+b)%3) {
        cout << "NO\n";
        return;
    }

    if(2*min(a,b)<max(a,b)) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
