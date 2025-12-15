#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int fodase;
    cin >> fodase;

    string a,b;
    cin >> a >> b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(a==b) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
