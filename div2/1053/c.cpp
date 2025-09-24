#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void make_sp(vector<ll> &sp, vector<ll> &v) {
    sp[0] = v[0];
    for(ull i=1;i<sp.size();i++) sp[i] = sp[i-1]+v[i];
}

ll get(vector<ll> &sp, int a, int b) {
    if(a==0) return sp[b];
    return sp[b]-sp[a-1];
}

void make_sp2(vector<ll> &sp, vector<ll> &v) {
    sp[0] = v[0];
    for(ull i=1;i<sp.size();i++) sp[i] = sp[i-1]+v[i]*(i&1?-1:1);
}

ll get2(vector<ll> &sp, int a, int b) {
    if(a==0) return sp[b];
    if(a&1) return sp[b]-sp[a-1];
    return sp[a-1]-sp[b];
}


void solve() {
    int n;
    cin >> n;

    vector<ll> v(2*n),sp(2*n),sp2(2*n);
    for(ll &i:v) cin >> i;

    make_sp(sp,v);
    make_sp2(sp2,v);


    for(int i=0;i<n;i++) {
        cout << get(sp,2*n-i-1,2*n-1)-
            get(sp,0,i) - 
            get2(sp2,i+1,2*n-i-2) << ' ';
    }
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
