#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    cout << 1 << ' ' << 1+rand()%1000000 << '\n';
    return 0;
}