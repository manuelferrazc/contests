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

    vector<ll> a(n), b(n);

    for(ll &i:a) cin >> i;
    for(ll &i:b) cin >> i;

    ll s = 0;
    for(int i=0;i<n;i++) s+=min(a[i],b[i]);

    string op;
    ll v,x;
    while(q--) {
        cin >> op >> x >> v;
        x--;
        s -= min(a[x],b[x]);
        if(op[0]=='A') a[x] = v;
        else b[x] = v;

        s+=min(a[x],b[x]);

        cout << s << '\n';
    }
    
    return 0;
}
