#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    string s;
    cin >> n >> k >> s;

    string r=s;
    reverse(r.begin(),r.end());
    if((s<r)) cout << "YES\n";
    else {
        for(int i=1;i<n and k;i++) {
            if(s[i]!=s[0]) {
                cout << "YES\n";
                return;
            }
        }
        cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
