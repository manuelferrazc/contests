#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    int n2 = n;

    vector<pair<int,int>> f;
    for(int i=2;i*i<=n2;i++) {
        if(n2%i==0) {
            f.push_back(pair(i,0));
            while(n2%i==0) {
                f.back().ss++;
                n2/=i;
            }
        }
    }

    if(n2>1) f.push_back(pair(n2,1));

    ll ans = 1;
    
    for(auto [p,q]:f) {
        // k^n tem q ser p^q*x, pra algum x
        // cada k tem q ter o teto de q/n

        int qtd = q/n;
        if(q%n) qtd++;
        for(int i=0;i<qtd;i++) ans*=p;
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
