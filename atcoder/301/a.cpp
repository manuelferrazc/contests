#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,t=0,a=0;
    string s;
    cin >> n >> s;
    for(auto i:s) {
        if(i=='T') t++;
        else a++;
    }

    if(t>a) cout << "T\n";
    else if(a>t) cout << "A\n";
    else if(s.back()=='A') cout << "T\n";
    else cout << "A\n";
}

int main() { _
    solve();

    return 0;
}
