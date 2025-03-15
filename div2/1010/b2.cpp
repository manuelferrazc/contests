#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    unsigned int x;
    int n,m;
    cin >> x >> n >> m;
    unsigned int rmax=0,rmin=0,xi=x;

    int mi=max(0,min(31,m));
    while(xi && mi) {
        xi=(xi+1)/2;
        mi--;
    }
    xi=xi>>min(31,n);
    rmin=xi;
    xi=x;
    mi=max(0,min(31,m));
    xi=xi>>min(31,n);
    while(xi && mi) {
        xi=(xi+1)/2;
        mi--;
    }
    rmax=xi;
    cout << rmin << ' ' << rmax << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
