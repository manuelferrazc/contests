#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int act=0,m=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='.') {
            act = 0;
            continue;
        } else {
            act++;
            m=max(m,act);
        }
    }

    if(m<k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
