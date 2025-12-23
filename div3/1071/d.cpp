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

    // set<int> s;
    // s.insert(0);
    // for(int i=0;i<=m;i++) s.insert(i);
    int m = (1<<n)-1;
    cout << m << ' ';
    m>>=1;
    cout << m << ' ';
    int i=n-2;

    while(i>=0) {
        m>>=1;
        cout << m << ' ';
        // cout << "ababa\n";
        for(int k=m+(1<<(i+1));k<(1<<n);k+=(1<<(i+1))) cout << k << ' ';
        // for(int k:s) cout << (m|k) << ' ';
        i--;
    }

    // for(int e:s) cout << e << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
