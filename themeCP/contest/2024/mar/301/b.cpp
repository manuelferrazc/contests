#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    
    string out(n+1,'2');
    int neq=0;
    for(int i=0;i<n-i-1;i++) if(s[i]!=s[n-i-1]) neq++;
    for(int i=0;i<=n;i++) {
        if(n&1){
            if(i<neq or n-2*neq<i-neq) out[i] = '0';
            else out[i] = '1';
        } else {
            if(i<neq or n-2*neq<i-neq or (i-neq)&1) out[i] = '0';
            else out[i] = '1';
        }
    }
    cout << out << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
