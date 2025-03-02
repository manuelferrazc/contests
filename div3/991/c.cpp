#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string n;
    cin >> n;

    ll sum = 0;
    for(auto &i:n) sum+=i-'0';


    if(sum==0) {
        cout << "YES\n";
        return;
    }

    ll t=0,d=0;
    for(ull i=0;i<n.size();i++) {
        if(n[i]=='3') t++;
        else if(n[i]=='2') d++;
    }

    for(int i=0;i<=min(5LL,t);i++) {
        for(int j=0;j<=min(8LL,d);j++) {
            if((sum+2*j+6*i)%9==0) {
                cout << "YES\n";
                return;
            }
        }
    }


    cout << "NO\n";
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
