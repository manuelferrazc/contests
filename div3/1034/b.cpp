#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,j,k;
    cin >> n >> j >> k;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    if(k>1) cout << "YES\n";
    else {
        int f = v[j-1];
        auto it = max_element(v.begin(),v.end());
        if(f>=*it) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
