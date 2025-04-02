#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    string s;
    cin >> s;

    set<char> m;

    if(s.size()&1) {
        cout << "No\n";
        return 0;
    }

    for(ull i=0;i<s.size();i+=2) {
        if(s[i]!=s[i+1]) {
            cout << "No\n";
            return 0;
        }
        if(m.count(s[i])) {
            cout << "No\n";
            return 0;
        }
        m.insert(s[i]);
    }

    cout << "Yes\n";

    return 0;
}
