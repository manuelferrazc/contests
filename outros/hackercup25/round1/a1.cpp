#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll solve() {
    int n;
    cin >> n;
    ll ant,r=0;
    cin >> ant;

    for(int i=1;i<n;i++) {
        ll act;
        cin >> act;
        r=max(r,abs(act-ant));
        ant = act;
    }

    return r;
}

int main() { _
    int t;
    cin >> t;

    for(int i=1;i<=t;i++) cout << "Case #" << i << ": " << solve() << '\n';
    return 0;
}
