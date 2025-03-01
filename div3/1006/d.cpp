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
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int a=0,b=0,max=0;

    for(int i=0;i<n;i++) {
        int men = 0,ma = 0;
        for(int j=i+1;j<n;j++) {
            if(v[i]<v[j]) ma++;
            else if(v[i]>v[j]) men++;

            if(men-ma>max) {
                max = men-ma;
                a=i;
                b=j;
            }
        }

    }

    cout << a+1 << ' ' << b+1 << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
