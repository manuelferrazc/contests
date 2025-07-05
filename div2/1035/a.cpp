#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int a,b,x,y;
    cin >> a >> b >> x >> y;

    if(a==b) cout << 0 << '\n';
    else if(a==b-1) {
        if(b&1) cout << min(x,y) << '\n';
        else cout << x << '\n';
    }
    else if(a==b+1 and (a&1)) cout << y << '\n';
    else if(a>b) cout << -1 << '\n';
    else {
        int c=0;
        for(int i=a;i!=b;i++) {
            if(i&1) c+=x;
            else c+=min(x,y);
        }
        cout << c << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
