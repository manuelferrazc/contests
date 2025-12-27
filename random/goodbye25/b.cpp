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
    int c = 0;

    if(s[0]=='u') {
        s[0] = 's';
        c++;
    }

    if(s.back()=='u') {
        s.back() = 's';
        c++;
    }

    for(int i=1;i<(int)s.size();i++) {
        if(s[i]=='u') {
            int st = i;
            while(s[i]=='u') i++;

            c+=(i-st)/2;
        }
    }

    cout << c << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
