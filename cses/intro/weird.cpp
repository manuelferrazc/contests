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
    ll n;
    cin >> n;

    cout << n << ' ';

    while(n!=1) {
        if(n&1) n = 3*n+1;
        else n>>=1;    
        cout << n << ' ';
    }
    cout << '\n';
    return 0;
}
