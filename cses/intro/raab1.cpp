#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,a,b;
    cin >> n >> a >> b;

    if(a+b>n or ((a==0) != (b==0))) cout << "NO\n";
    else {
        cout << "YES\n";
        vector<ll> va,vb;
        for(int i=n;i>a+b;i--) {
            va.push_back(i);
            vb.push_back(i);
        }
        int qtd = a+b;
        for(int i=1;i<=a;i++) {
            va.push_back(qtd-i+1);
            vb.push_back(a-i+1);
        }
        for(int i=1;i<=b;i++) {
            va.push_back(b-i+1);
            vb.push_back(qtd-i+1);
        }

        for(int i:va) cout << i << ' ';
        cout << '\n';
        for(int i:vb) cout << i << ' ' ;
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    
    return 0;
}
