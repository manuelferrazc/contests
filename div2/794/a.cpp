#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,s=0;
    cin >> n;
    vector<int> v(n);
    for(auto &i:v) {cin >> i;s+=i;}

    for(int i=0;i<n;i++) {
        if((s-v[i])%(n-1)) continue;
        if((s-v[i])/(n-1)==v[i]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
