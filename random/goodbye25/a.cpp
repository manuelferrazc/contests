#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no = "NO\n";

const char * solve() {
    string s;
    cin >> s;

    bool b=false;

    for(char c:s) {
        if(c=='Y') {
            if(b) return no;
            b = true;
        }
    }

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
