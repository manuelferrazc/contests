#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    ll n;
    cin >> n;

    if(n&1LL) {
        ll a = n>>1,b=a+1;
        if(b%10!=9 and a%10!=9) cout << a << ' ' << b << '\n';
        else {
            if(a&1) swap(a,b); // b é o com 9
            string s1=to_string(a),s2=to_string(b);
            if(s1.size()-s2.size()) s2="0"+s2;
            ll sa = 0, sb=0;
            for(auto i:s1) sa+=i-'0';
            for(auto i:s2) sb+=i-'0';

            for(ull i=0;i<s1.size();i++) {
                int x = min(s2[i]-s1[i],(int)(sb-sa)/2);
                if(x<0) continue;
                s1[i]+=x;
                s2[i]-=x;
                sa+=x;
                sb-=x;
            }
            cout << stoi(s1) << ' ' << stoi(s2) << '\n'; // ???
        }
    } else cout << (n>>1LL) << ' ' << (n>>1LL) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
