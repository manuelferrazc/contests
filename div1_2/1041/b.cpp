#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


void solve() {
    int n,x;
    cin >> n >> x;
    string s;
    cin >> s;

    int a=-1,b=-1;

    for(int i=x-2;i>=0;i--) {
        if(s[i]=='#') {
            a=i;
            break;
        }
    }

    for(int i=x;i<n;i++) {
        if(s[i]=='#') {
            b=i;
            break;
        }
    }

    if(a==-1 and b==-1) cout << 1 << '\n';
    else if(a==-1) cout << min(n-b+1,x) << '\n';
    else if(b==-1) cout << min(n-x+1,a+2) << '\n';
    else {
        if(s[x]=='#' or s[x-2]=='#') cout << min(x,n-x+1) << '\n';
        else cout << max(min(a+2,n-x+1),min(x,n-b+1)) << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
