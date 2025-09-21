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

    int v[2*n+1];
    v[1] = v[n+1] = n;
    int a=2;
    for(int x=n-1;x;x--) {
        v[a] = v[2*n-a+2] = x;
        a++;
    }

    for(int i=1;i<=2*n;i++) cout << v[i] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
