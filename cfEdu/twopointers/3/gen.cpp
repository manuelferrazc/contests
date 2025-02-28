#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char **argv) {
    srand(atoi(argv[1]));

    int n = 1+rand()%10;
    ll p = 1+rand()%1'000'000'000'000'000'000LL;
    cout << n << ' ' << p << '\n';
    for(int i=0;i<n;i++) cout << 1+rand()%1'000'000'000 << ' ';
    cout << '\n';
}