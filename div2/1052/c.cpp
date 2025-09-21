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

    if((s[0]=='0' and s[1]=='1') or (s[n-2]=='1' and s[n-1]=='0')) cout << "NO\n";
    else {
        vector<int> v(n);
        iota(v.begin(),v.end(),1);
        for(int i=1;i<n-1;i++) {
            if(s[i-1]=='1' and s[i]=='0' and s[i+1]=='1') {
                cout << "NO\n";
                return;
            }
        }

        int st,e;
        for(int i=0;i<n;i++) {
            if(s[i]=='0') {
                st = i;
                while(i<n and s[i]=='0') {
                    e = i;
                    i++;
                }
                int val = e+1;
                while(st<=e) {
                    v[st] = val--;
                    st++;
                }
            }
        }

        cout << "YES\n";
        for(int i:v) cout << i << ' ';
        cout << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
