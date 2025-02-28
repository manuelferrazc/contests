#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    cout << "1\n";
    srand(atoi(argv[1]));

    int n = 2 + rand()%100;

    cout << n << '\n';
    for(int i=0;i<n;i++) cout << 2+rand()%(n-1) << ' ';
    cout << '\n';

    return 0;
}