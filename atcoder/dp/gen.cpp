#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));

    int n = 1+rand()%500;

    cout << n << '\n';

    vector<int> v(n);
    iota(v.begin(),v.end(),1);

    while(v.size()) {
        int pos = rand()%v.size();
        cout << v[pos] << ' ';

        swap(v.back(),v[pos]);
        v.pop_back();
    }

    cout << '\n';

    for(int i=0;i<n;i++) cout << 1+rand()%1000'000'000 << ' ';
    cout << '\n';

    return 0;
}