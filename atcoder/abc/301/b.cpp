#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    int a,b; cin >> a;
    for(int i=1;i<n;i++) {
        cin >> b;
        if(a>b) {
            while(a-1>b) cout << a-- << ' ';
            cout << a << ' ';
            a = b;
        } else {
            while(a+1<b) cout << a++ << ' ';
            cout << a << ' ';
            a = b;
        }
    }
    cout << a << '\n';
}

int main() { _
    solve();

    return 0;
}
