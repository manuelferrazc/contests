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
    vector<int> a(n);
    for(int &i:a) cin >> i;

    if(n==1) cout << "NO\n";
    else {
        for(int i=0;i<n-1;i++) {
            if(a[i]>a[i+1]) {
                cout << "YES\n2\n" << a[i] << ' ' << a[i+1] << '\n';
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
