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

    int p = 0;
    int v[n];

    for(int i=0;i<n;i++) {
        cin >> i[v];
        if(v[i]&1) p|=1;
        else p|=2;
    }

    if(p==3) sort(v,v+n);

    for(int i=0;i<n;i++) cout << i[v] << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
