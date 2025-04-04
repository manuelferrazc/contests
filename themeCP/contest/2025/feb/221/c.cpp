#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,p=0;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]<v[p]) p = i;
    }

    for(int i=p+1;i<n;i++) {
        if(v[i]<v[i-1]) {
            cout << "-1\n";
            return;
        }
    }
    
    cout << p << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
