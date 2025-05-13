#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;
    vector<bool> v(n+1,true);

    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        v[x] = false;
    }

    for(int i=1;i<=n;i++) {
        if(v[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
