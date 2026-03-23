#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int n;
    cin >> n;

    int v[n];
    for(int i=0;i<n;i++) cin >> i[v];

    int g = v[0];
    for(int i=1;i<n;i++) g = gcd(g,v[i]);

    if(g==1) return 0;
    for(int i=n-1;i>=n-2;i--) {
        if(gcd(gcd(i+1,v[i]),g)==1) return n-i;
    }

    return 3;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
