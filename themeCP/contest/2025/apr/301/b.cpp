#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string a,b;
    cin >> a >> b;

    if(b[0]=='a' and b.size()==1) {
        cout << 1 << '\n';
        return;
    }

    for(char c:b) if(c=='a') {
        cout << -1 << '\n';
        return;
    }

    cout << (1LL<<a.size()) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
