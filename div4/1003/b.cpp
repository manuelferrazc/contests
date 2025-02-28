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
            cout << "1\n";
            return;
        }
    }

    cout << s.size() << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
