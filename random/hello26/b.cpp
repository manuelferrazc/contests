#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> c(n+1,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        c[x]++;
    }

    for(int i=0;i<k-1;i++) {
        if(c[i]==0) {
            cout << i << '\n';
            return;
        }
    }

    cout << k-1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
