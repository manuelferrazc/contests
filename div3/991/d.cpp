#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    // cout << "Teste novo\n";
    cin >> s;
    
    for(int i=0;i<s.size()-1;i++) {
        int m = i;
        // cout << "s[i] = " << s[i] << '\n';
        for(int j=1;j<9 and i+j<s.size();j++) {
            // cout << "s[i+j] = " << s[j+i] << "\n";
            if(s[i+j]-j>s[m]-(m-i)) {m=i+j;}
        }
        if(m==i) continue;
        // cout << "s[m] = " << s[m] << '\n';

        char aux = s[m]-(m-i);
        for(int j=m;j>i;j--) s[j] = s[j-1];
        s[i] = aux;
    }

    cout << s << '\n';
}

int main() { _
    int t; cin >> t;

    while(t--) solve();

    return 0;
}
