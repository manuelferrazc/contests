#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    
    int n = 1 + rand()%10000;
    int q = 1 + rand()%1000;
    cout << n << ' ' << q << '\n';

    vector<int> v(n);
    for(int i=0;i<n;i++) v[i] = i;

    while(v.size()>1) {
        cout << v.back()+1 << ' ' ;
        v.pop_back();

        cout << v[rand()%v.size()]+1 << ' ' << 1+rand()%400000 << '\n';
    }
 
    while(q--) {
        int v = 1+rand()%n;
        ll w = 1+rand()%4000000000;
        cout << v << ' ' << w << '\n';
    }

    return 0;
}