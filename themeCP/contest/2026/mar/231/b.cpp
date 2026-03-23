#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

const char * solve() {
    int n;
    string s;
    cin >> n >> s;

    if(s.front()=='1' or s.back()=='1') return yes;

    for(int i=1;i<n;i++) {
        if(s[i]=='1' and s[i-1]=='1') return yes;
    }

    return no;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
