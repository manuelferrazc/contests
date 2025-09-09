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

    int a=0,b=n-1,ans=0;
    while(true) {
        while(a<b and s[a]=='0') a++;
        while(b>=0 and s[b]=='1') b--;

        if(a<b) {
            swap(s[a],s[b]);
            ans++;
        } else break;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
