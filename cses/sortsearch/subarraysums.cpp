#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n, ans=0;
    ll act=0,x;
    cin >> n >> x;
    
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int a=0,b=0;b<n;b++) {
        act+=v[b];
        while(a<=b and act>x) act-=v[a++];
        if(act==x) ans++;
    }

    cout << ans << '\n';

    return 0;
}
