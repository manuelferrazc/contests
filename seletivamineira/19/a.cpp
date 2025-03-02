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
    int a,b;
    cin >> a >> b;
    if(a==1 and b==1) cout << n << '\n';
    else if(a==1 or b==1) cout << n/2 + (n&1) << '\n';
    else cout << (n/4) + (n%4!=0) << '\n';
}

int main() { _
    // int t; cin >> t;

    solve();

    return 0;
}
