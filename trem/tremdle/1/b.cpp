#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int x;
    cin >> x;
    int ans = x/5;
    if(x%5) ans++;
    cout << ans << '\n';
    return 0;
}
