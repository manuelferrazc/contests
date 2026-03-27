#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const ll mod = 1'000'000'007;
ll p[100'001];

int main() { _
    p[0] = 1;
    for(int i=1;i<100'001;i++) p[i] = (p[i-1]*2)%mod;

    int t;
    cin >> t;

    int n[t];
    for(int i=0;i<t;i++) cin >> n[i];
    while(t--) {
        int k;
        cin >> k;
        
        cout << p[k] << '\n';
    }

    return 0;
}
