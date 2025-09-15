#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int falta[4];
    for(int &i:falta) i=1;

    for(int i=0;i<10;i++) {
        int x;
        cin >> x;
        falta[x-1] = 0;
    }

    cout << falta[0]+falta[1]+falta[2]+falta[3] << '\n';
    
    return 0;
}
