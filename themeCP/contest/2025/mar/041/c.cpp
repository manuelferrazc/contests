#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int m,t,x;
    cin >> m;
    vector<int> v(30,0);

    while(m--) {
        cin >> t >> x;

        if(t==1) v[x]++;
        else {
            for(int i=29;i>=0 and x;i--) {
                if(v[i]==0) continue;
                x-=min(v[i],x/(1<<i))*(1<<i);
            }

            if(x==0) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
