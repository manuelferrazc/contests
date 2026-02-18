#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    int n = 1+rand()%1000;

    cout << n << '\n';
    while(n--) {
        cout << 1+rand()%1000 << ' ';
    }
    cout << '\n';


    return 0;
}
