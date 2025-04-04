#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++) {
        int x=1;
        if(i%4==1 or i%4==2) x=0;

        cout << x << ' ';
        m>>=1;
        for(int j=1;j<m;j++) {
            if(j&1) cout << 1-x << ' ' << 1-x << ' ';
            else cout << x << ' ' << x << ' ';
        }
        m<<=1;
        if(m%4) cout << 1-x << '\n';
        else cout << x << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
