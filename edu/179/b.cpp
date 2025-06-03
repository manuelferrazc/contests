#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int b[] = {0,1,2,3,5,8,13,21,34,55,89};

void solve() {
    int n,m;
    cin >> n >> m;

    while(m--) {
        int w,l,h;
        cin >> w >> l >> h;

        if(w<b[n] or l<b[n] or h<b[n]) cout << 0;
        else if (w>=b[n]+b[n-1] or l>=b[n]+b[n-1] or h>=b[n]+b[n-1]) cout << 1;
        else cout << 0;
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
