#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b and a==c or a==b+c or b==c+a or c==b+a) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
