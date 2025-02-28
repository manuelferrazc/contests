#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int ni=0, a;
    cin >> a;

    for(int i=1;i<=m or ni<n;) {
        if(ni<n and i<=m) {
            if(v[ni]<a) cout << v[ni++] << ' ';
            else {
                cout << a << ' ';
                cin >> a;
                i++;
            }
        } else if(ni<n) cout << v[ni++] << ' ';
        else {
            cout << a << ' ';
            cin >> a;
            i++;
        }
    }
    cout << '\n';

    return 0;
}
