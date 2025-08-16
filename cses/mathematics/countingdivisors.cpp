#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int mx = 1000001;
    vector<int> v(mx,0);
    for(int i=1;i<mx;i++) 
        for(int j=i;j<mx;j+=i) v[j]++;
    
    int t;
    cin >> t;

    while(t--) {
        cin >> mx;
        cout << v[mx] << '\n';
    }

    return 0;
}
