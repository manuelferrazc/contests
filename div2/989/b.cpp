#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k,ans=0;
    cin >> n >> m >> k;
    string s;
    cin >> s;

    int c=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            c++;
            if(c==m) {
                ans++;
                c=0;
                for(int j=0;j<k and i+j<n;j++) s[i+j] = '1';
            }
        } else c=0;
    }
    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
