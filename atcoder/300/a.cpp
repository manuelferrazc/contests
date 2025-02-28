#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n,a,b;
    cin >> n >> a >> b;
    a = a+b;
    for(int i=0;i<n;i++) {
        cin >> b;
        if(b==a) {
            cout << i+1 << '\n';
            return 0;
        }
    }

    return 0;
}
