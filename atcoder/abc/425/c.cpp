#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll get(ll *sp, int a, int b) {
    if(a>0) return sp[b]-sp[a-1];
    return sp[b];
}

int main() { _
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    ll sp[n];
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = v[i]+sp[i-1];

    int c=0,op,a,b;

    while(q--) {
        cin >> op >> a;

        if(op==1) c = (c+a)%n;
        else {
            cin >> b;
            a--;
            b--;
            a+=c;
            b+=c;

            a%=n;
            b%=n;
            if(a<=b) cout << get(sp,a,b) << '\n';
            else cout << get(sp,a,n-1)+get(sp,0,b) << '\n';
        }
    }

    return 0;
}
