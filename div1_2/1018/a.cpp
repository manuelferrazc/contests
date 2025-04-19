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

    int me=0;
    for(char c:s) if(c=='<') me++;
    int ma = me+1;
    vector<int> ans(n);
    ans[0] = me+1;
    
    for(int i=1;i<n;i++) {
        if(s[i-1]=='<') ans[i] = me--;
        else ans[i] = ++ma;
    }
    for(int i:ans) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
