#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%5;
    cout << 1 << '\n' << n << '\n';
    int q = 1+rand()%5;

    for(int i=0;i<q;i++) {
        int op = rand()&1;
        if(op) cout << "<- " << 1+rand()%(1LL<<(2*n)) << '\n';
        else cout << "-> " << 1+rand()%(1LL<<n) << ' ' 1+rand()%(1LL<<n) << '\n';        
    }
    
    return 0;
}