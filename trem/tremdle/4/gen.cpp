#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = rand()%20;
    cout << 1;
    for(int i=0;i<n;i++) cout << (rand()&1);
    cout << '\n';
    return 0;
}