#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n,m;
    cin >> n >> m;
    vector<long long> v(n,-1);

    while(m--) {
        long long op;
        cin >> op;

        if(op==1) {
            long long i,p;
            cin >> i >> p;
            v[i] = p;
        } else {
            long long l,r,p,ans=0;
            cin >> l >> r >> p;
            for(long long i=l;i<r;i++) if(v[i]!=-1 and v[i]<=p) {ans++; v[i] = -1;}
            cout << ans << '\n';           
        }
    }
}