#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    map<char,int> m;
    for(int i=0;i<n;i++) m[s[i]]++;
    for(int i=1;i<n-1;i++) if(m[s[i]]>1) {
        cout << "YES\n";
        return;
    }
    
    cout << "NO\n";
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
