#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "John\n";
const char * no  = "Brother\n";

void solve() {
    int n;
    cin >> n;

    int c=0,x=0;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        x^=a;
        if(a==1) c++;
    }

    if(c==n) {
        if(c&1) cout << no;
        else cout << yes;
        return;
    }

    if(x) cout << yes;
    else cout << no;
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
