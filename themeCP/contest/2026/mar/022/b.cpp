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

    int ans = 0;

    int i;
    for(i=n-1;s[i]=='0';i--) {}

    int last = i;
    for(int j=(i+1)%n;j!=i;j = (j+1)%n) {
        if(s[j]=='1') last = j;
        else {
            if(last<j) ans = max(ans,j-last);
            else ans = max(ans,n-last+j);
        }
    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
