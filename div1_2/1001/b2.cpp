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
    
    int a[n];

    for(auto &i:a) cin >> i;
    if(n==2) {
        if(a[0]>2&&a[1]>2) cout << "yes\n";
        else cout << "no\n";
        return;
    }
    bool p=0;
    for(int i=1;i<=n;i++) {
        if((a[i-1]-1)/2<max(n-i,i-1)) {
            p=1;
            cout << "no\n";
            return;
        }
    }
    if(not p) cout << "yes\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
