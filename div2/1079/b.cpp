#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no = "NO\n";

const char * solve() {
    int n;
    cin >> n;

    int p[n];
    for(int i=0;i<n;i++) cin >> p[i];
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];

    int x=0,y=0;

    while(x<n) {
        while(y<n and p[y]!=a[x]) y++;

        if(y==n) return no;
        x++;
    }

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
