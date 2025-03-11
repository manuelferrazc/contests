#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;

    int a=1,b=2,c=3;
    while(true) {
        int x;
        cout << "? " << a << ' ' << b << ' ' << c << '\n';
        cout.flush();
        cin >> x;
        if(x==0) {
            cout << "! " << a << ' ' << b << ' ' << c << '\n';
            return;
        }
        int r=rand()%3;
        if(r==0) a=x;
        else if(r==1) b=x;
        else c=x;
    }
}

int main() {
    srand(time(0)); 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
