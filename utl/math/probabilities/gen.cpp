#include <bits/stdc++.h>
using namespace std;

int get(int a, vector<int> &p) {
    return p[a] = p[a]==a? a : get(p[a],p);
}

bool unio(int a, int b, vector<int> &p, vector<int> &r) {
    a = get(a,p);
    b = get(b,p);
    if(a==b) return false;

    if(r[b]>r[a]) swap(a,b);
    else if(r[a]==r[b]) r[a]++;
    p[b] = a;
    return true;
}

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%13;
    cout << n << '\n';
    
    vector<int> p(n),r(n,1);
    iota(p.begin(),p.end(),0);

    for(int j=1;j<n;) {
        int a = 1 + rand()%n, b = 1+rand()%n;
        if(a==b) continue;

        if(unio(a-1,b-1,p,r)) {
            cout << a << ' ' << b << '\n';
            j++;
        }
    }

    return 0;
}