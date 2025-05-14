#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            set<char> s;
            s.insert('A');
            s.insert('B');
            s.insert('C');
            s.insert('D');

            s.erase(v[i][j]);
            if(i) s.erase(v[i-1][j]);
            if(j) s.erase(v[i][j-1]);

            v[i][j] = *s.begin();
        }
    }

    for(int i=0;i<n;i++) cout << v[i] << '\n';
    
    return 0;
}
