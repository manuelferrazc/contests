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

    for(ull i=0;i<s.size()-1;i++) {
        if(s[i]==s[i+1]) {
            cout << s[i] << s[i] << '\n';
            return;
        } else if (i<s.size()-2 and s[i]!=s[i+1] and s[i]!=s[i+2] and s[i+1]!=s[i+2]) {
            cout << s[i] << s[i+1] << s[i+2] << '\n';
            return;
        }
    }

    cout << "-1\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
