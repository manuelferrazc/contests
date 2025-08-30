#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll ume9 = 1e9;

int main() { _
    ll a,b,x1,x2,y1,y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    ll rx1 = x1+y1, ry1 = x1-y1;
    ll rx2 = x2+y2, ry2 = x2-y2;
    // cout << rx1 << ' ' << ry1 << '\n';
    // cout << rx2 << ' ' << ry2 << '\n';
    // swap(a,b);

    rx1+=2*a*ume9;
    rx2+=2*a*ume9;

    ry1+=2*b*ume9;
    ry2+=2*b*ume9;

    ll dx = max(rx1,rx2)/(2*a)-min(rx1-1,rx2-1)/(2*a);
    ll dy = max(ry1,ry2)/(2*b)-min(ry1-1,ry2-1)/(2*b);

    // cout << dx << ' ' << dy << '\n';
    cout << max(dx,dy) << '\n';

    return 0;
}
