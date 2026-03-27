#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int solve() {
    int a,b,c;
    cin >> a >> b >> c;

    if((a+b+c)&1) return -1;

    int ans = 0;

    for(int ab = 0;ab<=a;ab++) {
        for(int ac=0;ac+ab<=a;ac++) {
            for(int bc=0;bc+ab<=b;bc++) {
                if(ac+bc<=c) ans = max(ans,ab+ac+bc);
            }
        }
    }

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
