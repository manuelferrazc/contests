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

    if(n==3 or n==2) {
        cout << "NO SOLUTION\n";
        return 0;
    }

    for(int i=2;i<=n;i+=2) cout << i << ' ';
    for(int i=1;i<=n;i+=2) cout << i << ' ';
    cout << '\n';

    
    return 0;
}
