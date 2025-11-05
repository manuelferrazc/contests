#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    while(q--) {
        int l,r;
        cin >> l >> r;
        l--;
        r--;

        for(int i=100'000;;i--) {
            int qt=0;
            for(int j=l;j<=r;j++) if(v[j]>=i) qt++;
            if(qt>=i) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
