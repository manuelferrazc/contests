#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

const char * solve() {
    int n;
    cin >> n;

    int l = n*(n-1); // n*n -n = n(n-1)

    bool NO = false;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            int x;
            cin >> x;
            m[x]++;

            if(m[x]>l) NO = true;
        }
    }

    if(NO) return no;/////// vtncccccccccccccc

    return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
