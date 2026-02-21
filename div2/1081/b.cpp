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

    int q[2];
    q[1] = q[0] = 0;
    for(char c:s) q[c-'0']++;

    if(q[1]%2==0) {
        cout << q[1] << '\n';
        for(int i=0;i<n;i++) if(s[i]=='1') cout << i+1 << ' ';
        if(q[1]) cout << '\n';
        return;
    }

    if(q[0]&1) {
        cout << q[0] << '\n';
        for(int i=0;i<n;i++) if(s[i]=='0') cout << i+1 << ' ';
        cout << '\n';
        return;
    }

    cout << -1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
