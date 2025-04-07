#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int a,b;
    cin >> a >> b;
    cout << min(a,b) << ' ' << (max(a,b)-min(a,b))/2 << '\n';
    return 0;
}
