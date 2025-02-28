#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,t;
    cin >> n >> t;
    vector<int> v(n-1);
    for(auto &i:v) cin >> i;

    int x=1;
    while(x<t) x+=v[x-1];
    if(x==t) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    solve();
    return 0;
}
