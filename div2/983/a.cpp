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
    n<<=1;
    int z=0,u=0;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        if(x) u++;
        else z++;
    }
    n>>=1;
    cout << n-((z/2)+(u/2)) << ' ' << min(u,z) << '\n';
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}
