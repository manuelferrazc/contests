#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    
    int n = 1+rand()%9;

    cout << 1 << '\n' << n << '\n';

    vector<int> v(n);
    iota(v.begin(),v.end(),1);

    while(v.size()) {
        int p = rand()%v.size();

        cout << v[p] << ' ';
        swap(v.back(),v[p]);
        v.pop_back();
    }

    cout << '\n';


    return 0;
}
