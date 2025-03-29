#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string a,b;
    cin >> n >> a >> b;
    
    int q1=0,q2=0;
    for(int i=0;i<n;i++) {
        if(i&1) {if(a[i]=='0')q1++;}
        else if(b[i]=='0') q1++;
    }
    for(int i=0;i<n;i++) {
        if(i&1) {if(b[i]=='0')q2++;}
        else if(a[i]=='0') q2++;
    }

    if(q2>=((n>>1)+(n&1)) and q1>=(n>>1)) cout << "YES\n";
    else cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
