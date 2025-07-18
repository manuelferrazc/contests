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
    vector<int> p(n),s(n);

    for(int &i:p) cin >> i;
    for(int &i:s) cin >> i;

    if(p.back()!=s.front()) {
        cout << "NO\n";
        return;
    }

    for(int i=0;i<n-1;i++) {
        if(p[i]%p[i+1]) {
            cout << "NO\n";
            return;
        }
        int g = gcd(p[i+1],s[i]);
        if(gcd(p[i],s[i+1])!=g or g!=s[0]) {
            cout << "NO\n";
            return;
        }
    }

    for(int i=n-1;i;i--) {
        if(s[i]%s[i-1]) {
            cout << "NO\n";
            return;
        }
    }

    for(int i=0;i<n-1;i++) {
    }

    cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
