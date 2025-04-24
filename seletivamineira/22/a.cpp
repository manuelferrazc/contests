#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    vector<int> v(3);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(),v.end());
    if(v[0]+v[1]>v[2]) cout << "Yes\n";
    else cout << "No\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
