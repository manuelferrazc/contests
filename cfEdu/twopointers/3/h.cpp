#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n,m,s,A,B;
    cin >> n >> m >> s >> A >> B;
    vector<ll> a(n), b(m);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());

    ll l=0,r=0,w=0,c=0,ans=0;
    while(true) {
        if(w+A<=s) {
            w+=A;
            c+=a[l];
            l++;
            if(l==n) break;
        } else break;
    }
    
    ans=c;

    while(true) {
        if(w>s) {
            if(l==0) break;
            w-=A;
            c-=a[--l];
        } else {
            ans=max(ans,c);
            if(r==m) break;
            w+=B;
            c+=b[r++];
        }
    }

    cout << ans << '\n';

    return 0;
}
