#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char **argv) { _
    srand(atoi(argv[1]));

    int n = 200'000, m = 200'000;
    cout << n << ' ' << m << '\n';

    set<pair<int,int>> s;

    for(int i=0;i<m;) {
        int a = 1+rand()%n;
        int b = 1+rand()%n;

        if(a==b) continue;
        if(a>b) swap(a,b);

        if(s.count(pair(a,b))) continue;

        s.insert(pair(a,b));
        i++;
        cout << a << ' ' << b << '\n';
    }
    return 0;
}
