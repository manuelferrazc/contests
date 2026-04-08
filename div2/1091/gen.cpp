#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    
    int n = 1+rand()%60;
    int m = 1+rand()%60;

    cout << 1 << '\n' << n << ' ' << m << ' ';
    cout << 1+rand()%500 << ' ' << 1 +rand()%500 << '\n';

    return 0;
}
