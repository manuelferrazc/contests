#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
    srand(atoi(argv[1]));
    int n = 1+rand()%5000,m=1+rand()%5000;
    cout << n << ' ' << m << '\n';

    for(int i=0;i<m;i++) {
        int op = 1+(rand()&1);
        if(op == 1) {
            int l = rand()%n;
            int r = l+1+rand()%(n-l);
            cout << "1 " << l << ' ' << r << ' ' << rand()%10000 << '\n';
        } else {
            int l = rand()%n;
            int x = rand()%10000;
            cout << "2 " << x << ' ' << l << '\n';
        }
    }
    return 0;
}