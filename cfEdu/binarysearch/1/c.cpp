#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q,x,l,r,m;
    cin >> n >> q;

    vector<int> v(n+2);
    for(int i=1;i<=n;i++) cin >> v[i];
    v[0] = INT_MIN;
    v.back()=INT_MAX;

    while(q--) {
        cin >> x;
        l=0;
        r=n+1;

        while(l<r-1) {
            m = (l+r)>>1;
            
            if(v[m]>=x) r = m;
            else l = m;
        }
        cout << r << '\n';
    }

    return 0;
}
