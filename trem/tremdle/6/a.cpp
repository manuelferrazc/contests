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
    ll d1,d2,dl;
    cin >> d1 >> d2 >> dl;
    cout << min(2*min(d1+d2,min(d1,d2)+dl),d1+d2+dl) << '\n';
    return 0;
}
