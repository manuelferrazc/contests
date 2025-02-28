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

    vector<int> v(n);
    for(auto &i:v) cin >> i;

    while(q--) {
        cin >> x;
        l=0;
        r=n-1;

        while(l<=r) {
            m = (l+r)>>1;
            if(v[m]==x) {
                cout << "YES\n";
                m=-10;
                break;
            } else if(v[m]<x) l=m+1;
            else r=m-1;
        }
        if(m>=0) cout << "NO\n";
    }

    return 0;
}
