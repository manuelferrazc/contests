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
    string s;
    cin >> s;
    char act = s[0];
    cin >> s;
    s+=s;
    
    if(act=='g') {
        cout << 0 << '\n';
        return;
    }

    int min=0;
    for(int i=0;i<n;i++) {
        if(s[i]!=act) continue;
        int j = 0;
        for(;s[i+j]!='g';j++) {}
        min=max(min,j);
        i=i+j;
    }

    cout << min << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
