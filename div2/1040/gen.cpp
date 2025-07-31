#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%6;
    cout << 1 << '\n' << n << '\n';
    vector<int> perm(n);
    iota(perm.begin(),perm.end(),1);
    while(perm.size()) {
        int i = rand()%perm.size();

        cout << perm[i] << ' ';
        swap(perm[i],perm.back());
        perm.pop_back();
    }
    cout << '\n';
    return 0;
}