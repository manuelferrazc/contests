#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int a=-1,b=-1;
    for(int i=0;i<n;i++) {
        if(v[i]) {
            a=i;
            break;
        }
    }

    for(int i=n-1;i>=0;i--) {
        if(v[i]) {
            b=i;
            break;
        }
    }

    if(a==-1) cout << "YES\n";
    else if(b-a<x) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
