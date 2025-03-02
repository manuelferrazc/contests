#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

string s;
ll n;

void ff(ll a,ll i) {
    if(a>n) return;
    ll b=a;
    a|=(1LL<<ll(s.size()-i-1));
    if(a<=n) {
        for(ll j=i+1;j<=(ll)s.size();j++) {
            if(j==(ll)s.size()) {
                cout << a << endl;
                exit(0);
            }
            if(s[j]=='?') {
                ff(a,j);
                break;
            }
        }
    }
    for(ll j=i+1;j<=(ll)s.size();j++) {
        if(j==(ll)s.size()) {
            cout << b << endl;
            exit(0);
        }
        if(s[j]=='?') {
            ff(b,j);
            break;
        }
    }
}

void solve() {
    cin >> s >> n;
    ll a=0;
    for(auto i:s) {
        a<<=1LL;
        if(i=='1')a|=1LL;
    }
    
    if(a>n) {
        cout << "-1\n";
        return;
    }

    for(ull i=0;i<(ll)s.size();i++) {
        if(s[i]=='?') {
            ff(a,i);
            break;
        }
    }
    cout << a << '\n';
}

int main() { _
    solve();

    return 0;
}
