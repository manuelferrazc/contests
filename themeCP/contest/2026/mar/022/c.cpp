#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int qtd(int n,int m) {
    int r = 0;

    while(n>1) {
        int aux = n&1;
        n/=2;
        r++;
        if(aux) n++;
    }

    while(m>1) {
        int aux = m&1;
        m/=2;
        r++;
        if(aux) m++;
    }

    return r;
}

void solve() {
    ll n,m,x,y;
    cin >> n >> m >> x >> y;

    cout << 1 + min ({
        qtd(x,m),
        qtd(n-x+1,m),
        qtd(n,y),
        qtd(n,m-y+1)
    }) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
