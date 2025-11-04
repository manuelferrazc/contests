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


    for(int i=0;i<n;i++) {
        int v;
        cin >> v;

        if(i&1) v = -abs(v);
        else v = abs(v);

        cout << v << ' ';
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
