#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main(int argc, char  **argv) { _
    srand(atoi(argv[1]));

    int n = 1+rand()%10;
    int m = 1+rand()%10;
    cout << n << ' ' << m << '\n';

    for(int i=0;i<m;i++) {
        int op = 1+(rand()&1);
        int a = rand()%n;
        cout << op << ' ' << a;
        if(op==1) {
            int r = 1+a+rand()%(n-a),v = rand()%1'000'000'001;
            cout << ' ' << r << ' ' << v << '\n';
        } else cout << '\n';
    }

    return 0;
}
