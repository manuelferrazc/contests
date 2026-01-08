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
    
    int q0=0,q1=0;
    int v[n];

    for(int i=0;i<n;i++) {
        cin >> v[i];
        if(v[i]) q1++;
        else q0++;
    }

    int p1 = 0,s1 = 0;
    for(int i=0;i<n;i++) {
        if(v[i]==1) p1++;
        else break;
    }

    for(int i=n-1;i>=0;i--) {
        if(v[i]==1) s1++;
        else break;
    }

    int sz = 0;
    int mx = 0;
    for(int i=0;i<n;i++) {
        if(v[i]==0) {
            sz = 0;
            for(;i<n and not v[i];i++) sz++;
            mx = max(mx,sz);
        }
    }

    const char * a = "Alice\n";
    const char * b = "Bob\n";

    if(q0==0) cout << a;// ou tenho q fazer ser [0], ou [1,1,...,1,1] pra alice ganhar
    else if(v[0] or v[n-1]) cout << a;
    // else if(q1==0 and n%2==1) cout << a;
    // else if(p1==q1 or s1==q1) cout << a;
    else cout << b;
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
