#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct Stack {
    ll a,b,c,d;
};


void solve() {
    int n;
    cin >> n;

    vector<Stack> v(n);
    for(Stack &s:v) cin >> s.a >> s.b >> s.c >> s.d;

    ll ans=0;

    for(int i=0;i<n;i++) {
        Stack &s = v[i];
        if(s.b>s.d) {
            ans+=s.a;
            ans+=s.b-s.d;
            s.a=0;
        }
    }

    for(int i=0;i<n;i++) {
        Stack &s = v[i];

        if(s.a>s.c) ans+=s.a-s.c;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
