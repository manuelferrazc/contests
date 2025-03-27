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
    string s(n,'-');
    if(n&1) s[n>>1] = '=';
    else s[(n>>1)-1] = s[(n>>1)] = '=';
    cout << s << '\n';
}

int main() { _
    int t=1;
    while(t--) solve();
    return 0;
}
