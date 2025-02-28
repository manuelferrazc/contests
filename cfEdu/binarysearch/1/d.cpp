#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;



int main() { _
    int n,q,x,y,l,r,m,a,b;
    cin >> n;

    vector<int> v(n+2);
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = INT_MIN;
    v.back()=INT_MAX;
    sort(v.begin(),v.end());
    cin >> q;

    while(q--) {
        cin >> x >> y;
        l=0;
        r=n+1;

        while(l<r-1) {
            m = (l+r)>>1;
            
            if(v[m]>=x) r = m;
            else l = m;
        }
        a=r;
        l=0;
        r=n+1;
        
        while(l<r-1) {
            m = (l+r)>>1;
            
            if(v[m]>y) r = m;
            else l = m;
        }
        b=l;

        cout << b-a+1 << ' ';
    }
    cout << '\n';

    return 0;
}
