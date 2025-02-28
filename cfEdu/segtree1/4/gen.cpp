#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%10;
    int m = 1+rand()%20;
    cout << n << ' ' << m << '\n';
    for(int i=0;i<m;i++) {
        int op = rand()%2;
        if(op==1) cout << "1 " << rand()%n << ' ' << rand()%1'000'000'000 << '\n';
        else {
            int l = rand()%n;
            cout << "2 " << l << ' ' << l+(rand()%(n-l)) << ' ' << rand()%1'000'000'000 << '\n';
        }       
    }
    cout << '\n';
    return 0;
}