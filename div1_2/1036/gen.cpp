#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 2+ rand()%1000;
    cout << 1 << '\n' << n << '\n';
    for(int i=0;i<n;i++) cout << rand()%(n+1) << ' ';
    cout << '\n';
    return 0;
}