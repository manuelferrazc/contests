#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    vector<bool> p(100'001,false);
    p[0] = true;

    for(int c:v) {
        for(int i=99001;i>=0;i--) if(p[i]) p[i+c] = true;
    }

    cout << accumulate(p.begin(),p.end(),-1) << '\n';
    for(ull i=1;i<p.size();i++) if(p[i]) cout << i << ' ';
    cout << '\n';

    return 0;
}
