#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int mex(set<int> &s) {
    for(int i=0;;i++) if(s.count(i)==0ull) return i;
}

int main() { _
    int n1,n2,n3,k;
    cin >> n1 >> n2 >> n3 >> k;

    int v[k];
    for(int i=0;i<k;i++) cin >> v[i];

    int dp[101];
    dp[0] = 0;
    for(int i=1;i<101;i++) {
        set<int> s;
        for(int p:v) {
            if(i-p>=0) s.insert(dp[i-p]);

            dp[i] = mex(s);
        }
    }

    int x=dp[n1]^dp[n2]^dp[n3];

    if(x) cout <<  "Peter\n";
    else cout << "Vasya\n";

    return 0;
}
