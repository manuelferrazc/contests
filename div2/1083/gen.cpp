#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    
    int n = 1+rand()%100;
    cout << 1 << ' ' << n << '\n';

    vector<int> v;
    for(int i=1;i<=n;i++) v.push_back(i);

    while(v.size()) {
        int i = rand()%v.size();
        cout << v[i] << ' ';
        swap(v[i],v.back());
        v.pop_back();
    }
    cout << '\n';

    return 0;
}
