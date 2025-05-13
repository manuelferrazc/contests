#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    ll n;
    cin >> n;

    ll s = n*(n+1)/2;
    if(s&1) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    s>>=1;
    vector<ll> s1,s2;
    ll act=0;

    do {
        if(act+n<=s) {
            act+=n;
            s1.push_back(n);
        } else s2.push_back(n);

        n--;
    } while(n);

    cout << s1.size() << '\n';
    for(auto it = s1.rbegin(); it!=s1.rend();it++) cout << *it << ' ';
    cout << '\n';
    cout << s2.size() << '\n';
    for(auto it = s2.rbegin(); it!=s2.rend();it++) cout << *it << ' ';
    cout << '\n';

    return 0;
}
