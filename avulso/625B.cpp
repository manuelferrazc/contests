#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string s,t;
bool check(int x) {
    for(int i=0;i<t.size();i++) {
        if(i+x>=s.size()) return false; 
        if(t[i]!=s[i+x]) return false;
    }
    return true;
}

int main() { _
    cin >> s >> t;
    int ans=0, n=s.size();
    for(int i=0;i<n;) {
        if(check(i)) {
            ans++;
            i+=t.size();
        } else i++;
    }

    cout << ans << '\n';
    return 0;
}
