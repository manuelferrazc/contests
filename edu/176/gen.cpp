#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 3+rand()%500'000'000;
    cout << 1 << '\n' << n << ' ' << 1+rand()%n << '\n';
    return 0;
}