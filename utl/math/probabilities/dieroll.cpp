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
    a=max(a,b);

    switch (a) {
        case 1:
            cout << "1/1\n";
            break;
        case 2:
            cout << "5/6\n";
            break;
        case 3:
            cout << "2/3\n";
            break;
        case 4:
            cout << "1/2\n";
            break;
        case 5:
            cout << "1/3\n";
            break;
        case 6:
            cout << "1/6\n";
            break;
        default:
            cout << "Clube Atlético Mineiro.\n";
    }
    return 0;
}
