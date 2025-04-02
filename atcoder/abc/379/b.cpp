#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;

    int act = 0, ans = 0;
    for(auto c:s) {
        if(c=='X') act = 0;
        else {
            act++;
            if(act==k) {
                act=0;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
