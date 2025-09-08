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

    if(a==b) cout << 0 << '\n';
    else if(a%b==0 or b%a==0) cout << 1 << '\n';
    else cout << 2 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
