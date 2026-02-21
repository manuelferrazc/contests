#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    for(int i=0;i<n;i++) {
        int b = 1;
        string s2 = s.substr(i)+s.substr(0,i);
        for(int i=1;i<n;i++) if(s2[i]!=s2[i-1]) b++;
        ans = max(ans,b);
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
