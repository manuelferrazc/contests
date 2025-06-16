#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll w,h,a,b,x1,y1,x2,y2;
    cin >> w >> h >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    if((x1!=x2 and (x1-x2)%a==0) or (y1!=y2 and (y2-y1)%b==0)) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
