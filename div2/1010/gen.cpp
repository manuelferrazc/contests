#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    cout << "1\n";
    cout << 1+rand()%999'000'013 << ' ' << rand()%999'000'000 << ' ' << rand()%999'000'000 << '\n';
    return 0;
}