#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,a,b;
    cin >> n >> a >> b;

    vector<int> v(n,1);

    for(int i=0;i<a;i++) v[i] = 0;
    for(int i=n-b-2;i>=0;i--) v[i] = 0;

    cout << accumulate(v.begin(),v.end(),0) << '\n';
    return 0;
}
