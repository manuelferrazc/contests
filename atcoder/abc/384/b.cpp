#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool d(int r,int div) {
    if(div==1) return 1600<=r and r<2800;
    return 1200<=r and r<2400;
}

int main() { _
    int n,r;
    cin >> n >> r;

    vector<int> div(n),var(n);
    for(int i=0;i<n;i++) cin >> div[i] >> var[i];

    for(int i=0;i<n;i++) if(d(r,div[i])) r+=var[i];
    
    cout << r << '\n';

    return 0;
}
