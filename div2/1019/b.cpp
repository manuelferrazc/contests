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

    int inv=0;
    for(int i=1;i<n;i++) if(s[i]!=s[i-1]) inv++;

    if(inv==0) {
        if(s[0]=='1') n++;
        cout << n << '\n';
    } else if(inv<=2) cout << n+1 << '\n';
    else if(s[0]=='1' and s.back()=='0') cout << n+inv-1 << '\n';
    else cout << n+inv-2+(s[0]=='1') << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
