#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    
    int n = 1+rand()%10;
    cout << 1 << '\n' << n << '\n';

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout << 1;
            else cout << rand()%2;
        }
        cout << '\n';
    }

    return 0;
}
