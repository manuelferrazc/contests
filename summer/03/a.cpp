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
    
    int x=0;
    while(n--) {
        int a;
        cin >> a;
        x^=a;
    }

    if(x) cout << "first\n";
    else cout << "second\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
