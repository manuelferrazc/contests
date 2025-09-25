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

    int q0=0,qm=0;

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        if(x==0) q0++;
        if(x==-1) qm++;
    }

    if(qm&1) cout << q0+2 << '\n';
    else cout << q0 << '\n';
    
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
