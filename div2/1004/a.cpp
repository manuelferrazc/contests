#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int x,y;
    cin >> x >> y;

    if(x+1==y) cout << "Yes\n";
    else {
        if(x>y and (x-y+1)%9==0) cout << "Yes\n";
        else cout << "No\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
