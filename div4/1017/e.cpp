#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &i:v) cin >> i;

    vector<int> c(31,0);
    for(int i:v) {
        for(int j=0;i;j++) {
            if(i&1) c[j]++;
            i>>=1;
        }
    }

    ll m=0;
    for(int i=0;i<n;i++) {
        ll act=0;
        for(int j=0;j<31;j++) {
            if(((v[i]>>j)&1)==0) act+=(1LL<<j)*c[j];
            else act+=(1LL<<j)*(n-c[j]);
            
        }
        m=max(m,act);
    }
    cout << m << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
