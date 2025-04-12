#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n;
    string s;
    cin >> n >> s;
    map<char,ll> m;
    for(char c:s) m[c]++;

    if(n==1) {
        cout << "1\n";
        return 0;
    }

    ll ans = n*(n+1)/2;
    for(auto p:m) {
        ll qp = p.ss*(p.ss+1)/2;
        ans-=qp;
        ans+=p.ss+1;
    }

    cout << ans-m.size() << '\n';

    return 0;
}
