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
    
    if(x1<x2 and y1+b>y2 and (x2-x1)%a) cout << "NO\n";
    else if(x2<x1 and y2+b>y1 and (x1-x2)%a) cout << "NO\n";
    else if(y1<y2 and x1+a>x2 and (y2-y1)%b) cout << "NO\n";
    else if(y2<y1 and x2+a>x1 and (y1-y2)%b) cout << "NO\n";

    else if((min(x1,x2)+2*a<=max(x1,x2) and min(y1,y2)+2*b<=max(y1,y2)) and 
        ((max(y1,y2)-min(y1,y2))%b and max(x1,x2)-min(x1,x2))%a) cout << "NO\n";
    else cout << "YES\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
