#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> sq(31);

void solve() {
    int n,k;
    cin >> n >> k;

    vector<int> v;
    if(k==0) v = vector<int>(n,-13);
    for(int i=0;i<n and k;i++) {
        if(k<n-i) {
            while(v.size()!=n) v.push_back(-1);
            v[k+i-1] = 40;
            v[k+i] = -80;
            break;
        } else {
            k-=n-i;
            v.push_back(1000);
            if(k==0) while(v.size()!=n) v.push_back(-30);
        }
    }
    
    for(int i:v) cout << i << ' ';
    cout << '\n';
}

int main() { _
    for(int i=0;i<31;i++) sq[i] = (i*(i+1))>>1;
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
