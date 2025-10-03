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

    vector<int> oc(100,0);
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        oc[x-1] = 1;
    }

    cout << 2*accumulate(oc.begin(),oc.end(),0)-1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
