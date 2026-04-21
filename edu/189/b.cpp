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
    int n = s.size();

    int q = 0;
    for(int i=1;i<n;i++) if(s[i]==s[i-1]) q++;
    if(q>2) return no;

    for(int i=1;i+1<n;i++) if(s[i]==s[i-1] and s[i]==s[i+1]) {
        if(q>2) return no;
        q = 3;
    }

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
