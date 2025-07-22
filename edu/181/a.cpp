#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    string s;
    cin >> s;

    int qt=0,n=s.size();

    for(int i=0;i<n;i++) if(s[i]=='T') qt++;
    while(qt--) cout << 'T';
    for(int i=0;i<n;i++) if(s[i]!='T') cout << s[i];
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
