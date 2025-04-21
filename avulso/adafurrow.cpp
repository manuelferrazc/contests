#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int q;
    scanf("%d\n", &q);
    vector<bitset<20001>> v(20001,bitset<20001>());

    char c;
    int x,y;
    while(q--) {
        scanf("%c %d %d\n", &c, &x, &y);

        if(c=='+') v[x][y] = 1;
        else if(c=='-') v[x][y] = 0;
        else if(c=='v') printf("%lu\n", (v[x]|v[y]).count());
        else if(c=='^') printf("%lu\n", (v[x]&v[y]).count());
        else if(c=='!') printf("%lu\n", (v[x]^v[y]).count());
        else printf("%lu\n", (v[x]&(~v[y])).count());
    }

    return 0;
}
