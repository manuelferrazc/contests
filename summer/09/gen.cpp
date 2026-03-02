#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    int n = 1+rand()%10;    
    int m = rand()%(n*(n-1)/2+1);

    cout << n << ' ' << m << '\n';

    vector<pair<int,int>> v;
    for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) v.push_back(pair(i,j));
    // cout << v.size() << '\n';
    // cout.flush();

    // cout << n << ' ' << n*(n-1)/2 << '\n';
    // exit(0);

    while(m--) {
        int id = rand()%v.size();

        cout << v[id].ff << ' ' << v[id].ss << '\n';
        swap(v[id],v.back());
        v.pop_back();
    }

    return 0;
}