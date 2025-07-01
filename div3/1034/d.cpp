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

    int qt=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') qt++;
    }

    if(qt<=k) cout << "Alice\n";
    else if(qt>=2*k) cout << "Bob\n";
    else {
        int q = k;
        int a=0,b=n-1;
        while(a<b and q) {
            if(s[a]=='1' and s[b]=='1') {
                q--;
                s[a] = '0';
                if(q) {
                    q--;
                    s[b] = '0';
                } else {
                    a++;
                    break;
                }
            }
            else if(s[a]=='1') {
                q--;
                s[a]='0';
            } else if(s[b]=='1') {
                q--;
                s[b]='0';
            }
            a++;
            b--;
        }
        while(s[a]!='1') a++;
        while(s[b]!='1') b--;
        // cout << a << ' ' << b << ' ';
        if(a>=n-k and b<k) cout << "Alice\n";
        else cout << "Bob\n";
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
