#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,no=0, re=0;
    string s,t;
    cin >> n >> s >> t;

    for(int i=0;i<n;i++) {
        if(s[i]!=t[i]) no++;
        if(s[i]!=t[n-i-1]) re++;
    }

    cout << min(2*no-(no&1),(re ? 2*re-(1-(re&1)):2)) << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
