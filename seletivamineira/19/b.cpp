#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    double d=0,x;
    int n;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> x;
        d+=x;
    }
    cout << fixed << setprecision(8);
    cout << d/n << '\n';
}

int main() { _
    // int t; cin >> t;

    solve();

    return 0;
}
