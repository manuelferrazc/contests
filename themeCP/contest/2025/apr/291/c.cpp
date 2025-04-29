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
    
    vector<int> v(n);
    
    for(int &i:v) cin >> i;
    
    int a=0,b=n-1;
    int mi = 1,ma=n;

    while(true) {
        if(a>=b) {
            cout << "-1\n";
            return;
        } 

        if(v[a]==mi) {
            mi++;
            a++;
            continue;
        } else if(v[a]==ma) {
            ma--;
            a++;
        } else if(v[b]==mi) {
            mi++;
            b--;
        } else if(v[b]==ma) {
            ma--;
            b--;
        } else {
            cout << a+1 << ' ' << b+1 << '\n';
            return;
        }
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
