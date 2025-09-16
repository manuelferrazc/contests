#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q,a,b;
    cin >> n >> q;

    ll v[n],sp[n];
    cin >> v[0];
    sp[0] = v[0];

    for(int i=1;i<n;i++) {
        cin >> v[i];
        sp[i] = sp[i-1]+v[i];
    }

    while(q--) {
        cin >> a >> b;
        a--;
        b--;

        if(a) cout << sp[b]-sp[a-1] << '\n';
        else cout << sp[b] << '\n';
    }
    
    return 0;
}
