#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    ll a,b,c;
    cin >> a >> b >> c;
    for(ll i=1;i<10000;i++) {
        if(a%i or b%i) continue;
        if((a/i)*(b/i)==c) {
            ll l1=a/i,l2=b/i,l3=i;
            cout << 4*(l1+l2+l3) << '\n';
            break;
        }
    }
    return 0;
}
