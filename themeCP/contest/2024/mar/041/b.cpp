#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int x;
    cin >> x;

    vector<int> v(32,0);
    int i;
    for(i=1;;i++) {
        if((1<<i)>x) {
            i--;
            v[i] = 1;
            x-=(1<<(i));
            break;
        }
    }

    for(;i>=0 and x;i--) {
        if((1<<i)<=x) {
            x-=1<<i;
            v[i] = 1;
        }
    }

    for(int i=0;i<31;i++) {
        if(v[i]>=2) {
            v[i+1]+=(v[i]>>1);
            v[i]=v[i]&1;
        }
        if(v[i] and v[i+1]) {
            v[i] = -v[i];
            v[i+2]+= v[i+1];
            v[i+1] = 0; 
        }
    }

    cout << "32\n";
    for(auto ii:v) cout << ii << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
