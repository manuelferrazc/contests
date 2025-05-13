#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    string s;
    cin >> s;

    int ans = 1, act=1;
    for(ull i=1;i<s.size();i++) {
        if(s[i]==s[i-1]) {
            act++;
            ans = max(act,ans);
        } else act = 1;
    }

    cout << ans << '\n';
    
    return 0;
}
