#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n;

    for(int i=1;;i++) {
        for(int j=1;j<=n;j++) {
            int nx = j+i;
            if(nx>n) nx = nx%n;
            cout << j << ' ' << nx << '\n';

            cin >> x;
            if(x==1) return;
            if(x==-1) exit(0);
        }
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
