#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    string s;
    cin >> n >> s;

    reverse(s.begin(),s.end());
    ll u=0,c=0,a=0,b=0;
    for(;a<n;a++,b++) {
        if(b>=n) {
            cout << -1 << ' ';
            continue;
        }
        ll x = b;
        while(b<n and s[b]=='1') b++;
        if(b==n) {
            a--;
            continue;
        }
        
        c+=u;
        u+=b-x;
        c+=b-x;
        cout << c << ' ' ;
    }
    

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
