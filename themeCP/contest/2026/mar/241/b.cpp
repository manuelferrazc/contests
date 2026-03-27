#include <bits/stdc++.h>

// https://codeforces.com/problemset/problem/1957/B

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n,k;
    cin >> n >> k;

    if(n==1) {
        cout << k << '\n';
        return;
    }

    int l;
    for(l = 30;;l--) if(k&(1ll<<l)) break;
    
    ll a = (1ll<<(l))-1;
    ll b = k-a;;

    // for(int i = l;i>=1;i--) {
    //     if(((a|b)&(1ll<<i)) and ((a|b)&(1ll<<(i-1)))==0) {
    //         a+=1ll<<(i-1);
    //         b+=1ll<<(i-1);

    //         if(a&(1ll<<i)) a-=1ll<<i;
    //         else b-=1ll<<i;
    //     }
    // }

    cout << a << ' ' << b;
    for(int i=2;i<n;i++) cout << ' ' << 0;
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
