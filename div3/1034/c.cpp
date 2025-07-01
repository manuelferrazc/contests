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
    vector<int> v(n);
    for(int &i:v) cin >> i;

    vector<int> p(n),s(n);
    p[0] = v[0];
    for(int i=1;i<n;i++) p[i] = min(p[i-1],v[i]);
    s[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) s[i] = max(s[i+1],v[i]);

    for(int i=0;i<n;i++) {
        if(p[i]!=v[i] and s[i]!=v[i]) cout << 0;
        else cout << 1;
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
