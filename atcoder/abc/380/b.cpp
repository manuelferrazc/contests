#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    int c=0;
    for(ull i=1;i<s.size();i++) {
        if(s[i]=='-') c++;
        else {
            cout << c << ' ';
            c=0;
        }
    }
    cout << '\n';
}

int main() { _
    int t=1;// cin >> t;

    while(t--) solve();

    return 0;
}
