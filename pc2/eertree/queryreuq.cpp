#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool dp[10001][10001];

int main() { _
    int q;
    cin >> q;

    string in;
    cin >> in;

    string s;
    int n = 0;
    ll ans=0;

    for(char c:in) {
        if(c=='-') {
            n--;
            for(int i=0;i<=n;i++) {
                if(dp[i][n]) ans--;
            }
            s.pop_back();
        } else {
            s.push_back(c);
            ans++;
            dp[n][n] = true;

            if(n) {
                if(s[n-1]==s[n]) {
                    ans++;
                    dp[n-1][n] = true;
                } else dp[n-1][n] = false;
            }
            
            for(int i=0;i<n-1;i++) {
                if(s[i]==s[n] and dp[i+1][n-1]) {
                    ans++;
                    dp[i][n] = true;
                } else dp[i][n] = false;
            }
            
            n++;
        }

        cout << ans << ' ';
    }

    cout << '\n';

    return 0;
}
