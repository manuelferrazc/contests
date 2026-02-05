#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    int n = rand()%21 + 1;

    int m = n*(n-1)/2;

    cout << n << ' ' << m << '\n';
    m = m-n+1;
    set<pair<int,int>> s;
    for(int i=0;i<n-1;i++) {
        cout << i << ' ' << i+1 << '\n';
        s.insert({i,i+1});
    }

    while(m) {
        int a = rand()%n,b=rand()%n;
        if(a==b) continue;
        if(a>b) swap(a,b);

        if(s.count({a,b})==0ull) {
            s.insert({a,b});
            m--;
            cout << a << ' ' << b << '\n';
        }
    }

    cout << 0 << ' ' << 0 << '\n';


    return 0;
}
