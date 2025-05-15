#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int q=1;
    for(char c:s) if(c=='<') q++;
    int q2 = q+1;

    cout << q << ' ';
    q--;
    for(char c:s) {
        if(c=='<') cout << (q--) << ' ';
        else cout << q2++ << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
