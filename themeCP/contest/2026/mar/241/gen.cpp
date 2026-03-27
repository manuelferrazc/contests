#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    
    cout << 1 << '\n';

    int n = 1+rand()%200'000;
    int k = 1+rand()%1000'000'000;

    cout << n << ' ' << k << '\n';

    return 0;
}
