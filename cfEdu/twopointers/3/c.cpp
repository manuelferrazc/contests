#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,r;
    cin >> n >> r;
    vector<int> v(n);
    for(auto &i:v) cin >> i;
    
    ll ans=0;
    int a=0,b=1;
    while(b<n) {
        if(a>=b or (v[b]-v[a])<=r) b++;
        else {
            ans+=n-b;
            a++;
        }
    }

    cout << ans << '\n';

    return 0;
}
