#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n,k;
    string s;
    cin >> n >> k >> s;
    if(k&1) {
        multiset<char> a,b;

        for(int i=0;i<n;i++) {
            if(i&1) b.insert(s[i]);
            else a.insert(s[i]);
        }

        for(int i=0;i<n;i+=2) {
            s[i] = *a.begin();
            a.erase(a.begin());
        }
        for(int i=1;i<n;i+=2) {
            s[i] = *b.begin();
            b.erase(b.begin());
        }
    } else sort(s.begin(),s.end());
    
    cout << s << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
