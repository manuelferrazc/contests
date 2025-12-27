#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll ask(int l, int r) {
    println("? {} {}", l, r);
    ll ret;
    cin >> ret;
    return ret;
}

int find_half(int a, int b, ll sum) {
    int l=a, r=b-1;
    int ret=0;
    
    while(l<=r) {
        int m = (l+r)>>1;

        ll s = ask(a,m);
        if(2*s==sum) return m;
        else if(2*s<sum) {
            ret = m;
            l = m+1;
        } else r = m-1;
    }

    return ret;
}

void solve() {
    int l=1,r;
    cin >> r;

    ll s = ask(l,r);
    while(l<r) {
        int m = find_half(l,r,s);

        if(m>=(l+r)/2) l = m+1;
        else r=m;
        s/=2;
    }

    println("! {}",s);
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
