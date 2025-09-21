#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll x,y;
    cin >> x >> y;

    if(x<y) cout << "2\n";
    // pula 1, pula y, pula x-y
    else if(x>y and (x-1)-y>0 and y!=1) cout << "3\n";
    else cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
