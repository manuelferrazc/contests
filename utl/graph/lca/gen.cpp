#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1 + rand()%1000;
    int q = 1 + rand()%1000;
    cout << n << ' ' << q << '\n';
    for(int i=1;i<n;i++) cout << 1+rand()%i << ' ';
    cout << '\n';
    for(int i=0;i<q;i++) cout << 1+rand()%n << ' ' << 1+rand()%n << '\n';
    return 0;
}