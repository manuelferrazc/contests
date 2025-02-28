#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,m,k;
    cin >> n >> m >> k;
    if(k>max(n,m)) {
        cout << "-1\n";
        return;
    }

    bool inv(false);
    if(m>n) {
        swap(n,m);
        inv = true;
    }

    string s;

    int x = n/k, y = m/k;
    if(n%k) x++;
    if(m%k) y++;
    
    int imprimiu = k;
    while(n or m) {
        if(imprimiu==0 and n) {
            cout << "-1\n";
            return;
        }
        s+=string(min({k,n,imprimiu}),'0');
        n-=min({k,n,imprimiu});
        s+=string(min(k,m),'1');
        imprimiu = min(k,m);
        m-=imprimiu;
    }
    
    if(inv) for(auto &i:s) i = (i=='0'?'1':'0');
    cout << s << '\n';
    
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
