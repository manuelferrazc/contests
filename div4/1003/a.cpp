#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;
    cout << s.substr(0,s.size()-2) << "i\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
